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
