#include <unistd.h>

void	expand_str(char *s)
{
	int	flag = 0;
	int	i = 0;

	while (s[i] < 33)
		i++;
	while (s[i])
	{
		if (s[i] < 33)
			flag = 1;
		else
		{
			if (flag)
				write(1, "   ", 3);
			write(1, &s[i], 1);
			flag = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
}
