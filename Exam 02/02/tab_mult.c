#include <unistd.h>

int ft_atoi(char *s)
{
	int n = 0;

	while (*s >= '0' && *s <= '9')
	{
		n = n * 10 + (*s - '0');
		s++;
	}
	return (n);
}

void ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

void tab_mult(char *s)
{
	int n = ft_atoi(s);
	int i = 1;
	
	while (i < 10)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(n * i);
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(argv[1]);
	else
		write(1, "\n", 1);
}

/*Assignment name  : tab_mult
Expected files   : tab_mult.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que muestre la tabla de multiplicar de un número.

El parámetro siempre será un número estrictamente positivo que quepa en un int,
y dicho número multiplicado por 9 también cabrá en un int.

Si no hay parámetros, el programa muestra \n.

Ejemplos:

$>./tab_mult 9
1 x 9 = 9
2 x 9 = 18
3 x 9 = 27
4 x 9 = 36
5 x 9 = 45
6 x 9 = 54
7 x 9 = 63
8 x 9 = 72
9 x 9 = 81
$>./tab_mult 19
1 x 19 = 19
2 x 19 = 38
3 x 19 = 57
4 x 19 = 76
5 x 19 = 95
6 x 19 = 114
7 x 19 = 133
8 x 19 = 152
9 x 19 = 171
$>
$>./tab_mult | cat -e
$
$>
--------------------------------------------------------------------------------*/
