#include <unistd.h>

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	main(int argc, char **argv)
{
	//(void)argv;
	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return(0);
}

/*Assignment name  : paramsum
Expected files   : paramsum.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que muestre el número de argumentos pasados a él, seguido de
una nueva línea.

Si no hay argumentos, simplemente muestra un 0 seguido de una nueva línea.

Ejemplos:

$>./paramsum 1 2 3 5 7 24
6
$>./paramsum 6 12 24 | cat -e
3$
$>./paramsum | cat -e
0$
$>
--------------------------------------------------------------------------------*/
