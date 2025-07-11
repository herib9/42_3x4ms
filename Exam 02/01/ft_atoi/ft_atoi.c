#include <stdio.h>

int	ft_atoi(const char *str)
{
	int	i = 0;
	int	num = 0;
	int	neg = 1;

	while (str[i] < 33)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{	
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{	
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (neg * num);
}	

int	main(void)
{
	printf("%i\n", ft_atoi("+188"));
	return (0);
}

/*teniendo el numero 318, este proceso haria:
	 * num(0) = 0 * 10 + (3 - 0) = 3
	 * num(3) = 3 * 10 + (1 - 0) = 31
	 * num(31) = 31 * 10 + (8 - 0) = 318*/
	 
/*
Assignment name  : ft_atoi
Expected files   : ft_atoi.c
Allowed functions: None
--------------------------------------------------------------------------------

Escribe una función que convierta el argumento del string str a un entero 
(tipo int) y lo devuelva.

Funciona de manera similar a la función atoi(const char *str) estándar,
consulta el manual.

Tu función debe declararse de la siguiente manera:

int	ft_atoi(const char *str)
--------------------------------------------------------------------------------
*/
