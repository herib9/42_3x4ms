#include <stdlib.h>
#include <unistd.h>

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(char *s, int n)				//funcion para odenar un str con una longitud dada
{
	int i = 0;							//posicion actual que estamos ordenando
	while (i < n - 1) 					//n-1 porque solo necesitamos ordenar hasta el penultimo elemento, el ultimo se ordena solo
	{
		int j = i + 1;					//j es el elemento que comparamos con s[i]
		while (j < n) 					//recorre los elementos desde i+1 hasta el final
		{
			if (s[i] > s[j])			//si el caracter en s[i] es mayor a s[j]
				swap(&s[i], &s[j]);		//los intercambia
			j++;						
		}
		i++;
	}
}
/*genera todas las combinaciones posibles de los caracteres de un str
*res = str que estamos construyendo
*pos = str de chars disponibles
*used = array de flags que marca que caracteres ya usamos
pos = posicion actual en res que estamos llenando
n = longitud total del str
*/
void perm(char *res, char *opc, int *used, int pos, int n)
{
	int	i = 0;					//recorre todos los chars disponibles en opc
	if (pos == n)				//cuando pos llega al final
	{
		write(1, res, n);		//escribe el resultado
		write(1, "\n", 1);
		return;
	}
	while (i < n)								//bucle para probar cada caracter
	{
		if (!used[i])							//verifica si el caracter ha sido usado
		{
			res[pos] = opc[i];					//coloca el char opc[i] en la pos de resultado
			used[i] = 1;						//marca el caracter como usado
			perm(res, opc, used, pos + 1, n);	//llamada recursiva para llenar la siguiente posicion(pos+1)
			used[i] = 0;						//desmarca el caracter
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	int i = 0;
	while (av[1][i])						// Calcular longitud
		i++;
	int n = i;								//almacena la longitud del str
	char *s = malloc(n + 1);				//copia y ordena el str original
	char *res = malloc(n + 1);				//almacena cada permutacion construida
	int *used = calloc(n, sizeof(int));		//array de flags para marcar caracteres usados
	i = -1;
	while (++i < n)
		s[i] = av[1][i];					// Copiar string en s para no modificar el original
	s[n] = 0;								//termina s en '\0' para hacerlo valido
	res[n] = 0;								//idem
	sort(s, n);								//ordena para generar permutaciones en orden alfabetico
	perm(res, s, used, 0, n);				//llamamos a perm para generar e imprimir todas las permutaciones

	free(s);								//liberamos memoria
	free(res);
	free(used);
	return (0);
}

/*Assignment name  : permutations
Expected files   : *.c *.h
Allowed functions: puts, malloc, calloc, realloc, free, write
-------------------------------------------------------------------------

Escribe un programa que imprima todas las permutaciones de una cadena dada como argumento.
Las soluciones deben darse en orden alfabético.
No probaremos tu programa con cadenas que contengan duplicados (por ejemplo: «abccd»).

Por ejemplo, esto debería funcionar:

$> ./permutations a | cat -e
a$

$> ./permutations ab | cat -e
ab$
ba$

$> ./permutations abc | cat -e
abc$
acb$
bac$
bca$
cab$
cba$*/