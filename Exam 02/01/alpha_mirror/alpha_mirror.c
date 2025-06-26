#include <unistd.h>

void	am(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] =  122 - (s[i] - 97);
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = 90 - (s[i] - 65);
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		am(argv[1]);
	write(1, "\n", 1);
	return (0);
}

