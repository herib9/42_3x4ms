#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int	*array;
	int	len;
	int	i = 0;
	
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	array = malloc (len * sizeof(int));
	while (i < len)
	{
		array[i] = end;
		if (end < start)
			end++;
		else if(end > start)
			end--;
		i++;
	}
	return(array);
}

int main(void)
{
        int i = 0;
        int *arr = ft_rrange(0, 4);
        while (i < 5)
        {
                printf("%i ", arr[i]);
                i++;
        }
        free(arr);
}

/*
--------------------------------------------------------------------------------
Escribe la siguiente función:

int     *ft_rrange(int start, int end);

Debe asignar (con malloc()) un array de enteros, llenarlo con valores 
consecutivos que comienzan en end y terminan en start (¡Incluyendo start y end!)
luego devolver un puntero al primer valor del array.

Ejemplos:

- Con (1, 3) devolverá un array que contiene 3, 2 and 1
- Con (-1, 2) devolverá un array que contiene 2, 1, 0 and -1.
- Con (0, 0) devolverá un array que contiene 0.
- Con (0, -3) devolverá un array que contiene -3, -2, -1 and 0.
--------------------------------------------------------------------------------
*/
