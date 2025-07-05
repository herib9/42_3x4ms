#include <unistd.h>

void	cap(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if ((s[i] >= 'a' && s[i] <= 'z') && (s[i - 1] <= 32 || s[i - 1] == 0))
			s[i] -= 32;
		write(1, &s[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2)
		cap(argv[1]);
	write(1, "\n", 1);
}
