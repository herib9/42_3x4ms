#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(char *s)
{
	int	n = 0;
	int	i = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	return (n);
}

void	print_hex(int n)
{
	if (n >= 16)
		print_hex(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		print_hex(ft_atoi(argv[1]));
		//write(1, "\n", 1);
		//print_hex(atoi(argv[1]));
	}
	write(1, "\n", 1);
	return (0);
}

/*Assignment name  : print_hex
Expected files   : print_hex.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome un número positivo (o cero) expresado en base 10,
y lo muestre en base 16 (letras minúsculas) seguido de una nueva línea.

Si el número de parámetros no es 1, el programa muestra una nueva línea.

Ejemplos:

$> ./print_hex "10" | cat -e
a$
$> ./print_hex "255" | cat -e
ff$
$> ./print_hex "5156454" | cat -e
4eae66$
$> ./print_hex | cat -e
$
--------------------------------------------------------------------------------*/
