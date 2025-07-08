#include <unistd.h>

void	rotone(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'y') || (s[i] >= 'A' && s[i] <= 'Y'))
			s[i] += 1;
		else if (s[i] == 'z' || s[i] == 'Z')
			s[i] -= 25;
		write(1, &s[i], 1); 
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}
