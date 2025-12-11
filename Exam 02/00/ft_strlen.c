#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int main (void)
{
	char  *s = "paquete";
	int i = 0;
	i = ft_strlen(s);
	printf("%d\n", i);
}

/*Assignment name  : ft_strlen
Expected files   : ft_strlen.c
Allowed functions:
--------------------------------------------------------------------------------

Escribe una función que devuelva la longitud de un string.

Tu función debe ser declarada de la siguiente manera:

int	ft_strlen(char *str)

--------------------------------------------------------------------------------*/
