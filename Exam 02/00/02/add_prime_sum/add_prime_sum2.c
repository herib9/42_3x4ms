#include <unistd.h>

void	p_nbr(int n)
{
	if (n > 9)
		p_nbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	ft_atoi(char *s)
{
	int	i = 0;
	int	num = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num);
}

int	apm(int n)
{
	int	div = 3;

	if (n < 2)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);
	while (div < n)
	{
		if (n % div == 0)
			return (0);
		div += 2;
	}
	return (1);
}

int	main(int ac, char **av)
{

	int	result = 0;
	
	if (ac == 2)
	{        
		int     n = ft_atoi(av[1]);
		while (n > 0)
		{
			if (apm(n))
				result += n;
			n--;
		}
		p_nbr(result);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);
}
		

