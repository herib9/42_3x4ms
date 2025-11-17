#include <stdlib.h>
#include <stdio.h>

int	*nums;
int	target;
int	actual[100];

void	powerset(int pos, int size, int tam, int suma)
{
	if (suma == target)
	{
		int	i = 0;
		while (i < tam)
		{
			if (i > 0)
				printf(" ");
			printf("%d", actual[i++]);
		}
		printf("\n");
		return;
	}
	if (pos >= size)
		return;
	powerset(pos + 1, size, tam, suma);
	actual[tam] = nums[pos];
	powerset(pos + 1, size, tam + 1, suma + nums[pos]);
}

int	main(int ac, char **av)
{
	int	pos = 0;
	if (ac < 3)
		return (1);
	target = atoi(av[1]);
	if (!(nums = malloc(sizeof(int) * (ac - 2))))
		return (1);
	while (pos < ac - 2)
	{
		nums[pos] = atoi(av[pos + 2]);
		pos++;
	}
	powerset(0, ac - 2, 0, 0);
	free(nums);
	return (0);
}
