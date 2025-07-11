#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int pgcd(char *none, char *ntwo)
{
	int n1 = atoi(none);
	int n2 = atoi(ntwo);
	int i = n2;
	while (i != 1)
	{
		if ((n1 % i == 0) && (n2 % i == 0))
			return(i);
		i--;
	}
	return(i);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
		printf("%i\n", pgcd(argv[1], argv[2]));
	return(0);
}

/*
Assignment name  : pgcd
Expected files   : pgcd.c
Allowed functions: printf, atoi, malloc, free
--------------------------------------------------------------------------------

Escribe un programa que tome dos strings representando dos enteros estrictamente
positivos que quepan en un int.

Muestra su Máximo Común Divisor seguido de una nueva línea (siempre es un
entero estrictamente positivo).

Si el número de parámetros no es 2, muestra una nueva línea.

Examples:

$> ./pgcd 42 10 | cat -e
2$
$> ./pgcd 42 12 | cat -e
6$
$> ./pgcd 14 77 | cat -e
7$
$> ./pgcd 17 3 | cat -e 
1$
$> ./pgcd | cat -e
$
--------------------------------------------------------------------------------
*/
