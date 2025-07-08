#include <unistd.h>

void	fw(char *s)
{
	int	i = 0;

	while (s[i] <= 32)
		i++;
	while (s[i] != 32 && s[i] != 9)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fw(argv[1]);
	write(1, "\n", 1);
	return (0);
}

