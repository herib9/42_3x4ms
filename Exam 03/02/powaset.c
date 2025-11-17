#include <stdlib.h>
#include <stdio.h>

int	*nums;
int	target;
int	actual[100];

void	powaset(int	pos_nums, int total_nums, int pos_actual, int suma)
{
	if (suma == target)
	{
		int i = 0;
		while (i < pos_actual)
		{
			if (i > 0)
				printf(" ");
			printf("%d", actual[i++]);
		}
		printf("\n");
		return;
	}
	if (pos_nums >= total_nums)
		return;
	powaset(pos_nums + 1, total_nums, pos_actual, suma);
	actual[pos_actual] = nums[pos_nums];
	powaset(pos_nums + 1, total_nums, pos_actual + 1, suma + nums[pos_nums]);
}

int	main(int ac, char **av)
{
	int	pos_nums = 0;
	if (ac < 3)
		return (1);
	target = atoi(av[1]);
	if (!(nums = malloc(sizeof(int) * (ac - 2))))
		return (1);
	while (pos_nums < ac - 2)
	{
		nums[pos_nums] = atoi(av[pos_nums + 2]);
		pos_nums++;
	}
	powaset(0, ac - 2, 0, 0);
	free(nums);
	return(0);
}
