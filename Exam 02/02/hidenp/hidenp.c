#include <unistd.h>

void	hidenp(char *s, char *d)
{
	int	i = 0;
	int	j = 0;
	int	len = 0;

	while (s[len])
		len++;
	while (d[i])
	{
		if(s[j] == d[i])
			j++;
		i++;
	}
	if (len == j)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
}
