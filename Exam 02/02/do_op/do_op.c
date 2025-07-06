#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	do_op(char *num1, char *sign, char *num2)
{
	int	n1 = atoi(num1);
	int 	n2 = atoi(num2);
	int	result;

	if (*sign == '+')
		result = n1 + n2;
	if (*sign == '-')
		result = n1 - n2;
	if (*sign == '*')
		result = n1 * n2;
	if (*sign == '/')
		result = n1 / n2;
	if (*sign == '%')
		result = n1 % n2;
	printf("%i\n", result);
}

int	main(int ac, char **av)
{
	if (ac == 4)
		do_op(av[1], av[2], av[3]);
	else
		write(1, "\n", 1);
}
