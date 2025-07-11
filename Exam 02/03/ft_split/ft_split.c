#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char	**ft_split(char *s)
{
	int	i = 0;
	int	j;
	char	*start;
	char	**word = malloc(100 * sizeof(char *));
	
	if(!word)
		return (NULL);
	while(*s)
	{
		while(*s == ' ' || *s == '\t' || *s == '\n')
			s++;
		if(!s)
			break;
		start = s;
		while(*s && !(*s == ' ' || *s == '\t' || *s == '\n'))
			s++;
		word[i] = malloc(s - start + 1);
		j = 0;
		while(start < s)
			word[i][j++] = *start++;
		word[i][j] = '\0';
		i++;
	}
	word[i] = NULL;
	return(word);
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		char **words = ft_split(av[1]);
		int	i = 0;
		while (words[i])
		{
			printf("palabra %d: %s\n", i + 1, words[i]);
			free(words[i]);
			i++;
		}
		free(words);
	}
	return (0);
}

/*
Assignment name  : ft_split
Expected files   : ft_split.c
Allowed functions: malloc
--------------------------------------------------------------------------------

Escribe una función que tome una cadena, la divida en palabras y las devuelva 
como un array de cadenas terminado en NULL.

Una "palabra" se define como una parte de una cadena delimitada por 
espacios/tabulaciones/nuevas líneas, o por el inicio/fin de la cadena.

Tu función debe ser declarada de la siguiente manera:

char    **ft_split(char *str)
--------------------------------------------------------------------------------
*/
