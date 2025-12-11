#include <stdio.h>
#include <stdlib.h>
//#include <limits.h>

char *ft_itoa(int nbr) 
{
	int	num = nbr;
	int	len = 0;
	char *	result;

	if (nbr <= 0)
		len++;
	while (num) 
	{
	        num = num / 10;
	        len++;
	}
	result = malloc(len + 1);
	result[len] = '\0';
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
	{
	        result[0] = '-';
	        nbr = -nbr;
	}
	while (nbr) 
	{
	        result[--len] = nbr % 10 + '0';
	        nbr /= 10;
	}	
	return (result);
}

int main(void)
{
	int	n = -123;
	int	b = 123;
	int	c = 0;
	printf("%s\n", ft_itoa(n));
	printf("%s\n", ft_itoa(b));
	printf("%s\n", ft_itoa(c));
	//printf("%s\n", ft_itoa(INT_MAX));
	//printf("%s\n", ft_itoa(INT_MIN));
}

/*Assignment name  : ft_itoa
Expected files   : ft_itoa.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Escribe una función que tome un entero y lo convierta en una cadena terminada
en nulo.

La función devuelve el resultado en un array de caracteres que debes asignar.

Tu función debe ser declarada de la siguiente manera:

char	*ft_itoa(int nbr)
--------------------------------------------------------------------------------*/
