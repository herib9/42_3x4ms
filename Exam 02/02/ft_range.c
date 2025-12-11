#include <stdlib.h>
#include <stdio.h>

int     *ft_range(int start, int end)
{       
        int     i = 0;
        int     size = 0;
        int     *num;
        
        if (start > end)
                size = (start - end + 1);
        else
                size = (end - start + 1);
        num = malloc(size * sizeof(int));
        while (i < size)
        {
                num[i] = start;
                if (start < end)
                        start++;
                else if (start > end)
                        start--;
                i++;
        }
        return (num);
}


int main(void)
{
	int i = 0;
	int *arr = ft_range(0, 4);
	while (i < 5)
	{
		printf("%i ", arr[i]);
		i++;
	}	
	free(arr);
}

/*Assignment name  : ft_range
Expected files   : ft_range.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Escribe la siguiente función:

int     *ft_range(int start, int end)

Debe asignar memoria (con malloc()) para un array de enteros, llenarlo con 
valores consecutivos que comiencen en start y terminen en end (¡Incluyendo 
start y end!), luego devolver un puntero al primer valor del array.

Ejemplos:

- Con (1, 3) devolverá un array que contiene 1, 2 and 3.
- Con (-1, 2) devolverá un array que contiene -1, 0, 1 and 2.
- Con (0, 0) devolverá un array que contiene 0.
- Con (0, -3) devolverá un array que contiene 0, -1, -2 and -3.
--------------------------------------------------------------------------------*/
