#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char    **ft_split(char *s) 
{
    int i = 0;
    int letra = 0;
    int word = 0;
    char **split = malloc (sizeof(char *) * 10000);

    while (s[i])
    {   
        split[word] = malloc (sizeof(char) * 10000);
        letra = 0;
        while (s[i] < 33 && s[i] != '\0')
            i++;
        if (s[i] == '\0')
            break ;
        while (s[i] >= 33) 
        {   
            split[word][letra] = s[i];
            letra++;
            i++;
        }   
        split[word][letra] = '\0';
        word++;
    }   
    split[word] = '\0';
    return (split);
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
--------------------------------------------------------------------------------
Función que toma un string, lo divide en palabras y las devuelve como un array
de strings terminado en NULL.

Una "palabra" se define como una parte de un string delimitada por 
espacios/tabulaciones/nuevas líneas, o por el inicio/fin del string.
--------------------------------------------------------------------------------
*/
