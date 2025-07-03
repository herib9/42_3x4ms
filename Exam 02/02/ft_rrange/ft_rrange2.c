#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int i = 0;
	int size; 
	if (start < end)
		size = (end - start + 1);
	else
		size = (start - end + 1);
	int *nums = malloc(size * sizeof(int));
	//if (!nums)
	//	return (NULL);
	//podemos omitir estas dos ultimas lineas
	if (start < end)
	{
		while (start <= end)
		{
			nums[i] = end;
			i++;
			end--;
		}
	}
	else
	{
		while (start >= end)
		{
			nums[i] = end;
			i++;
			end++;
		}
	}
	return (nums);
}

#include <stdio.h>

int	main()
{
	int	*arr = ft_rrange(0, -3);
	int	size = 0;

	while (size < 4)
	{
		printf("%i ", arr[size]);
		size++;
	}
	free(arr);
}
