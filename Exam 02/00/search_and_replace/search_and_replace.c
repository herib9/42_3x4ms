#include <unistd.h>

void	sr(char *s, char *old, char *new)
{
	int	i = 0;

	while (s[i] && new[1] == '\0')
	{
		if (s[i] == *old)
			s[i] = *new;
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		sr(argv[1], argv[2], argv[3]);
	write(1, "\n", 1);
	return (0);
}

/* otra forma seria

void	sr(char *s, char *old, char *new)
{
	int	i = 0;

	while (s[i] && new[1] == '\0')
	{
		if (s[i] == *old)
			write(1, new, 1);
		else
			write(1, &s[i], 1);
		i++;
	}
}*/
