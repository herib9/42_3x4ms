#include <unistd.h>

void	lw(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	i--;
	while (s[i] <= 32)
		i--;
	while (s[i] > 32)
		i--;
	i++;
	while (s[i] > 32)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		lw(av[1]);
	write(1, "\n", 1);
}
