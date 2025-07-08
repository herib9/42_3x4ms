#include <unistd.h>

void	s2c(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] == '_')
		{
			i++;
			s[i] -= 32;
			write(1, &s[i], 1);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		s2c(av[1]);
	write(1, "\n", 1);
}
