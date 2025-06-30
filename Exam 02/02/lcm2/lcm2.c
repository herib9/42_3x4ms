#include <unistd.h>
#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;
	
	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
	return (n);
}

int	main(void)
{
	int	n1 = 5;
	int	n2 = 2;
	printf("%i\n", lcm(n1, n2));
}
	
/*int	main(int ac, char **av)
{
	if (ac == 3)
		lcm(av[1], av[2]);
	write(1, "\n", 1);
}*/

/*unsigned int    hcf(unsigned int a, unsigned int b)
{
	unsigned int	temp;

	temp = 0;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

unsigned int    ft_absolute(int producto)
{
	unsigned int v_absolute;
	
	v_absolute = producto;

	if (producto < 0)
		v_absolute = producto * (-1);

	return (v_absolute);
}*/
