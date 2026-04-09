#include <stdio.h>
#include <stdlib.h>				//cambiar malloc.h por stdlib.h
#include <ctype.h>

/*el programa funciona como una escalera de importancia
	- ADD mira hay sumas, pero antes le pregunta a MULT
	- MULT mira si hay multiplicaciones, pero antes le pregunta a VAL
	- VAL saca el num o resuelve lo que haya entre parentesis
  luego todo se va conectando hacia arriba, formando una estructura jerarquica*/

typedef struct node {			//no changes
	enum {
		ADD,
		MULTI,
		VAL
	}	type;
	int val;
	struct node	*l;
	struct node	*r;
}	node;

node	*new_node(node n)		//no changes
{
	node	*ret = calloc(1, sizeof(n));	//pide memoria al sistema para un nuevo nodo
	if (!ret)								//si el sistema no tiene mem...
		return (NULL);						//...devuelve NULL
	*ret = n;								//copia los datos que me pasaste al nuevo espacio de mem
	return (ret);							//devuelve la direccion de ese nuevo nodo
}

void	destroy_tree(node *n)	//no changes
{
	if (!n)								//si el nodo esta vacio, no haga nada
		return ;
	if (n->type != VAL)					//si NO es num(es una operacion)
	{
		destroy_tree(n->l);				//borra lo que haya a la izquierda
		destroy_tree(n->r);				//ve a borrar todo lo que haya a la derecha
	}
	free(n);							//libera la memoria de este nodo
}

void	unexpected(char c)
{
	if (c)
		printf("Unexpected token '%c'\n", c);
	else
		printf("Unexpected end of input\n");	//swap in the message file for input
}

int	accept(char **s, char c)
{
	if (**s == c)				//el char actual es igual a 'c' (es un '+'?)
	{							//add == c
		(*s)++;					//si lo es, avanza al siguiente char
		return (1);
	}
	return (0);					//si no, devuelve falso
}

int	expect(char **s, char c)
{
	if (accept(s, c))
		return (1);
	unexpected(**s);
	return (0);
}

node	*add(char **s);
node	*multi(char **s);
node	*val(char **s);

node	*add(char **s)
{
	node	*ret = multi(s);
	node	*right;

	while(ret && accept(s, '+'))
	{
		if(!(right = multi(s)))
		{
			destroy_tree(ret);
			return NULL;
		}
		if(!(ret = new_node((node){.type = ADD, .l = ret, .r = right})))
		{
			destroy_tree(right);
			return NULL;
		}
	}
	return ret;
}

node	*multi(char **s)
{
	node	*ret = val(s);
	node	*right;

	while(ret && accept(s, '*'))
	{
		if(!(right = val(s)))
		{
			destroy_tree(ret);
			return NULL;
		}
		if(!(ret = new_node((node){.type = MULTI, .l = ret, .r = right})))
		{
			destroy_tree(right);
			return NULL;
		}
	}
	return ret;
}

node	*val(char **s)
{
	node	*ret;

	if(isdigit(**s))
	{
		ret = new_node((node){.type = VAL, .val = **s - '0'});
		(*s)++;
		return ret;
	}
	if(accept(s, '('))						//Empieza con un parentesis? '('
	{	
		ret = add(s);						//Si si, resuelve todo lo de dentro llamando a 'add'
		if(!ret || !expect(s, ')'))			//Si falla o no se cierra parentesis...
		{
			destroy_tree(ret);
			return NULL;
		}
		return ret;
	}
	unexpected(**s);						//si no es numero ni '(' es un error
	return NULL;
}

node	*parse_expr(char *s)
{
	node	*ret = add(&s);		//add this line

	if (ret && *s)				//add ret &&
	{
		unexpected(*s);			//add this line
		destroy_tree(ret);
		return (NULL);
	}
	return (ret);
}

int	eval_tree(node *tree)
{
	switch (tree->type)
	{
		case ADD:
			return (eval_tree(tree->l) + eval_tree(tree->r));
		case MULTI:
			return (eval_tree(tree->l) * eval_tree(tree->r));
		case VAL:
			return (tree->val);
	}
	return (0);					//add this line
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	node *tree = parse_expr(argv[1]);
	if (!tree)
		return (1);
	printf("%d\n", eval_tree(tree));
	destroy_tree(tree);
	return (0);					//add this line
}