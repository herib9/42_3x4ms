#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

char    *ft_strdup(char *src)
{
	int	i = 0;
	char	*dup;

	while(src[i])
		i++;
	dup = malloc(i + 1);
	i = 0;
	while(src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return(dup);
}

int	main(int argc, char **argv)
{
	char	*s;

	s = "hola";
	if (argc == 2)
		ft_strdup(argv[1]);
	printf("%s\n", s);
	return (0);
}

/*Assignment name  : ft_strdup
Expected files   : ft_strdup.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Reproduce el comportamiento de la función strdup (man strdup).

Tu función debe ser declarada de la siguiente manera:

char    *ft_strdup(char *src)
--------------------------------------------------------------------------------*/
