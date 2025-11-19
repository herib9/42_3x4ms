#include <stdlib.h>
#include <stdio.h>

int	*nums;
int	target;
int	actual[100];

void	powaset(int p_nums, int size, int p_actual, int suma)
{
	if (suma == target)
	{
		int i = 0;
		while (i < p_actual)
		{
			if (i > 0)
				printf(" ");
			printf("%d", actual[i++]);
		}
		printf("\n");
		return;
	}
	if (p_nums == size)
		return;
	powaset(p_nums + 1, size, p_actual, suma);
	actual[p_actual] = nums[p_nums];
	powaset(p_nums + 1, size, p_actual + 1, suma + nums[p_nums]);
}

int	main(int ac, char **av)
{
	int i = -1;
	if (ac < 3 || !(nums = malloc(sizeof(int) * (ac - 2))))
		return 1;
	target = atoi(av[1]);
	while (++i < ac - 2)
		nums[i] = atoi(av[i + 2]);
	powaset(0, ac - 2, 0, 0);
	free(nums);
	return 0;
}
