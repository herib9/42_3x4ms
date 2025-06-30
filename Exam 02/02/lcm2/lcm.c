#include <stdio.h>

int	euclides(int a, int b)
{
	int	temp;
	while (b != 0)
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	return (a);
}

unsigned int	lcm(unsigned int a, unsigned int b)
{
	int	res;

	if ((int)a < 0 || (int)b < 0)
		return(0);
	res = 0;
	res = (a / euclides(a, b)) * b;
	return(res);
}

/*int	main(void)
{
	int	n1 = 0;
	int	n2 = 1;
	printf("%i\n", lcm(n1, n2));
}*/

//(lcm)ft_minimo_comun_multiplo(a, b) = (ft_absolute)ft_valor_absoluto(a * b) / (hcf)ft_maximo_comun_divisor(a, b)


//lcm(a, b) = (|a * b|) / (hcf(a, b))
//producto = a * b

