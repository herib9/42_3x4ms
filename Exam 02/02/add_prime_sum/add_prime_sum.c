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

/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: 
--------------------------------------------------------------------------------

Escriba un programa que tome dos strings y verifique si es posible escriba el 
primer string con caracteres del segundo string, respetando el orden en que 
aparecen estos caracteres en el segundo string.

Si es posible, el programa muestra el string, seguido de un \n, de lo contrario
simplemente muestra un \n.

Si el numero de argumentos no es 2, el programa muestra un \n.

Ejemplos:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e\
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e\
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e\
quarante deux$
$>./wdmatch "error" "rrerrrfiiljdfxjyuifrrvcoojh" | cat -e\
$
$>./wdmatch | cat -e\
$
--------------------------------------------------------------------------------
*/

