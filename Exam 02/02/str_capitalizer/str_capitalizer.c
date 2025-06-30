#include <unistd.h>

void	str(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if ((s[i] >= 'a' && s[i] <= 'z') && (s[i - 1] == ' ' || s[i - 1] == '\t' || s[i - 1] == 0))
			s[i] -= 32;
		write(1, &s[i], 1);
		i++;
	}
}


int	main(int argc, char **argv)
{
        int     i = 1;

        if (ac == 1)
                write(1, "\n", 1);
        while (ac > i)
        {
                strcap(av[i]);
                write(1, "\n", 1);
                i++;
        }
}

