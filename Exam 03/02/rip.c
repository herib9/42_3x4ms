#include <stdio.h>

int	invalid(char *s)
{
	int i = 0;
	int open = 0;
	int close = 0;

	while (s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')		//si encuentra '(' incrementa contador open
		{
			if (open > 0)			//si hay parentesis abiertos pendientes
				open--;				//los empareja y decrementa open
			else					//si no, ese parentesis está de mas
				close++;
		}
		i++;
	}
	return (open + close);			//retorna el total de parentesis que sobran
}
/*remove: parentesis a eliminar(calculado por valid)
del: parentesis ya eliminados
pos: posicion actual en el string*/
void result(char *s, int remove, int del, int pos)
{
	if (remove == del && !invalid(s))				//si del == remove y la cadena es valida
	{
		puts(s);									//imprime la solucion y termina
		return ;
	}
	while (s[pos])
	{
		if (s[pos] == '(' || s[pos] == ')')			//si encuentra '(' ó ')'
		{
			char c = s[pos];						//guarda una copia para modificar s[pos] temporalmente
			s[pos] = ' ';							//lo reemplaza por espacio
			result(s, remove, del + 1, pos + 1);	//llama recursivamente con del+1 (1 eliminacion mas)
			s[pos] = c;								//restaura el parentesis guardado en c a s[pos]
		}
		pos++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
		result(av[1], invalid(av[1]), 0, 0);
	return (ac != 2);
}

/*llama a result con el argumento pasado, al numero de eliminaciones necesarias
del = 0 -> aun no se ha eliminado nada)
pos = 0 -> empezando desde el inicio

Assignment name  : rip
Expected files   : *.c *.h
Allowed functions: puts, write
--------------------------------------------------------------------------------

Escribe un programa que tome como argumento una cadena que contenga solo paréntesis.
Si los paréntesis no están equilibrados (por ejemplo, «()»),
tu programa deberá eliminar el número mínimo de paréntesis para que la expresión quede equilibrada.
Por eliminar nos referimos a sustituirlos por espacios.
A continuación, imprimirás todas las soluciones (puede haber más de una).

El orden de las soluciones no es importante.

Por ejemplo, esto debería funcionar:
$> ./rip '(()' | cat -e
 ()$
( )$
$> ./rip '((()()())())' | cat -e
((()()())())$
$> ./rip '()())()'| cat -e
()() ()$
()( )()$
( ())()$
$> ./rip '(()(()(' | cat -e
(()  ) $
( )( ) $
( ) () $
 ()( ) $*/
