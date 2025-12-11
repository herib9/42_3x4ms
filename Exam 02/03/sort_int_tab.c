#include <stdio.h>

void	sit(int *tab, unsigned int size)
{
	unsigned int	i = 0;
	int	temp;

	while (i < size - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		i++;
	}
}

int	main(void)
{
	int	tab[] = {12, 2, 16, 5, 14};
	int	len = 5;
	int	i = 0;
	
	sit(tab, len);
	
	while (i < len)
	{
		printf("%i ", tab[i]);
		i++;
	}
}

/*Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Escribe la siguiente función:

void sort_int_tab(int *tab, unsigned int size)

Debe ordenar (en su sitio) el array int 'tab', que contiene exactamente el
tamaño de 'size', en orden ascendente.

Los dobles deben preservarse.

La entrada es siempre coherente.
--------------------------------------------------------------------------------*/
