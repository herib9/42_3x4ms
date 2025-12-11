#include <unistd.h>

void	ft_putnbr(int n)
{
	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_atoi(char *s)
{
	int nb = 0;
		
	while (*s >= '0' && *s <= '9')
	{
		nb = nb * 10 + (*s - '0');
		s++;
	}
	return (nb);
}

int	is_prime(int n)
{
	int i;
	
	if (n < 2)
		return (0);
	i = 2;
	while (i <= n / 2)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

void	add_prime_sum(char *s)
{
	int n = ft_atoi(s);
	int sum = 0;
	int i = 2;
	
	while (i <= n)
	{
		if (is_prime(i))
			sum += i;
		i++;
	}
	ft_putnbr(sum);
}

int main(int argc, char **argv)
{
	if (argc == 2)
		add_prime_sum(argv[1]);
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}

/*Assignment name  : add_prime_sum
Expected files   : add_prime_sum.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Escribe un programa que tome un entero positivo como argumento y muestre la suma
de todos los números primos inferiores o iguales a él, seguido de un \n.

Si el número de argumentos no es 1, o el argumento no es un número positivo,
simplemente muestra 0 seguido de un salto de línea.

Ejemplos:

$>./add_prime_sum 5
10
$>./add_prime_sum 7 | cat -e
17$
$>./add_prime_sum | cat -e
0$
$>
--------------------------------------------------------------------------------*/

