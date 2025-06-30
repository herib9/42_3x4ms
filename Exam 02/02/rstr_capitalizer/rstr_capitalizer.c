#include <unistd.h>

void    rstr(char *s)
{
	int	i = 0;

    while (s[i])
    {
        if ((s[i] >= 'a' && s[i] <= 'z') && (s[i + 1] ==  ' ' || s[i + 1] == '\t' || s[i + 1] == '\0'))
		s[i] -= 32;
	else if ((s[i] >= 'A' && s[i] <= 'Z') && (s[i + 1] ==  ' ' || s[i + 1] == '\t' || s[i + 1] == '\0'))
		i = i;
	else if (s[i] >= 'A' && s[i] <= 'Z')
		s[i] += 32;
        write(1, &s[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
	if (argc == 2)
		rstr(argv[1]);
	write(1, "\n", 1);
}
