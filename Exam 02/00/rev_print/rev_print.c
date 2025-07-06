#include <unistd.h>

void	rev(char *s)
{
	int	i = 0;
	
	while (s[i])
		i++;
	i--;
	while (s[i])
	{
		write(1, &s[i], 1);
		i--;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rev(argv[1]);
	write(1, "\n", 1);
}

/*
si te pide un char * como devolucion y no te deja usar write ni printf, esta seria la funcion

char	*rev_print(char *s)
{
	int	i = 0;
	int	len = 0;
	int	temp;
	
	while (s[len])
		len++;
	len--;
	while (i < len)
	{
		temp = s[i];
		s[i] = s[len];
		s[len] = temp;
		i++;
		len--;
	}
	return (s);
}

int	main()
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
}
*/
