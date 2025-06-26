#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	if (n == 0)
		return 0;
	while (n % 2 == 0)
		n = n / 2;
	return (n == 1);
}

int main(void)
{
	printf("%i\n", is_power_of_2(0));
	printf("%i\n", is_power_of_2(2));
	printf("%i\n", is_power_of_2(3));
	printf("%i\n", is_power_of_2(1));
}
