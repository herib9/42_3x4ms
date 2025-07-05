#include <unistd.h>

void    rcap(char *s)
{
	int	i = 0;

    while (s[i])
    {
        if ((s[i] >= 'a' && s[i] <= 'z') && (s[i + 1] <= 32 || s[i + 1] == '\0'))
		s[i] -= 32;
	else if ((s[i] >= 'A' && s[i] <= 'z') && (s[i + 1] <= 32 || s[i + 1] == '\0'))
		i = i;
	else if (s[i] >= 'A' && s[i] <= 'Z')
		s[i] += 32;
        write(1, &s[i], 1);
        i++;
    }
}

int     main(int ac, char **av)
{
        int     i = 1;

        if (ac == 1)
                 write(1, "\n", 1);
        while (i < ac)
        {
                rstr(av[i]);
                write(1, "\n", 1);
                i++;
        }
}

