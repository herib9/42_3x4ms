#include <stdlib.h>

int	*ft_range(int start, int end)
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
			nums[i] = start;
			i++;
			start++;
		}
	}
	else
	{
		while (start >= end)
		{
			nums[i] = start;
			i++;
			start--;
		}
	}
	return (nums);
}

#include <stdio.h>

int	main()
{
	int	*arr = ft_range(0, 4);
	int	size = 0;

	while (size < 5)
	{
		printf("%i ", arr[size]);
		size++;
	}
	free(arr);
}
