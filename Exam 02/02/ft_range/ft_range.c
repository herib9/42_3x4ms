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
