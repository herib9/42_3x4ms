#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
//	return (n != 0 && (n & (n - 1)) == 0);
	if (n == 0)
		return 0;
	while (n > 1)
	{
		if (n % 2 == 0)
			n = n / 2;
		else
			return (0);
	}			
	return (1);
}

int main(void)
{
	printf("%i\n", is_power_of_2(0));
	printf("%i\n", is_power_of_2(2));
	printf("%i\n", is_power_of_2(3));
	printf("%i\n", is_power_of_2(1));
}
