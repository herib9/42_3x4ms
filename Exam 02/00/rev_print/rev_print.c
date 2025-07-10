#include <unistd.h>

void    rev_print(char *s)
{
    int i = 0;

    while (s[i])
        i++;
    i--;
    while (s[i])
    {
        write(1, &s[i], 1);
        i--;
    }
}

int main(int argc, char **argv)
{
    if (argc == 2)
        rev_print(argv[1]);
    write(1, "\n", 1);
    return (0);
}

#include <stdio.h>
#include <unistd.h>



/*int	main()
{
	char	s[] = "hola";
	printf("%s\n", rev(s));
}

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 2)
	{
		rev(av[1]);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}	
	write(1, "\n", 1);
}*/
