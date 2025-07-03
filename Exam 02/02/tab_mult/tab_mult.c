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
