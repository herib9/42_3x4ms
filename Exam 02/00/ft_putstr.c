#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;	
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		ft_putstr(av[1]);
	write(1, "\n", 1);
}

/*Assignment name  : ft_putstr
Expected files   : ft_putstr.c
Allowed functions: write
--------------------------------------------------------------------------------
Escribe una función que muestre un string en la salida estándar.

El puntero pasado a la función contiene la dirección del primer carácter del
string.

Tu función debe ser declarada de la siguiente manera:

void	ft_putstr(char *str)
--------------------------------------------------------------------------------*/
