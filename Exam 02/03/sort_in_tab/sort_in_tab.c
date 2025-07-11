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
		else
			i++;
	}
}

/*
Assignment name  : sort_int_tab
Expected files   : sort_int_tab.c
Allowed functions:
--------------------------------------------------------------------------------

Escribe la siguiente función:

void sort_int_tab(int *tab, unsigned int size)

Debe ordenar (en su sitio) el array int 'tab', que contiene exactamente el
tamaño de 'size', en orden ascendente.

Los dobles deben preservarse.

La entrada es siempre coherente.
--------------------------------------------------------------------------------
*/
