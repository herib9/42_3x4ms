#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int start, int end)
{
	int	*array;
	int	len;
	int	avanza;
	int	i = 0;
	
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	array = malloc(sizeof(int) * len);
	if (!array)
		return NULL;
	if (start < end)
		avanza = 1;
	else
		avanza = -1;
	while (i < len)
	{
		array[i] = start + (i * avanza);
		i++;
	}
	return array;
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
