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

int         is_power_of_2(unsigned int n)
{       
        if (n == 0)
                return (0);
        if (n / 2)
        {       
                if (n % 2 == 0)
                        return (1);
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

/*Assignment name  : is_power_of_2
Expected files   : is_power_of_2.c
Allowed functions: None
--------------------------------------------------------------------------------

Escribe una función que determine si un número dado es una potencia de 2.

Esta función devuelve 1 si el número dado es una potencia de 2, de lo contrario 
devuelve 0.

Tu función debe ser declarada de la siguiente manera:

int	    is_power_of_2(unsigned int n)
--------------------------------------------------------------------------------*/
