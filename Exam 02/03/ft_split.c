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

/*Assignment name  : ft_list_remove_if
Expected files   : ft_list_remove_if.c
Allowed functions: free
--------------------------------------------------------------------------------

Escriba una función llamada ft_list_remove_if que elimine de la lista pasada
cualquier elemento cuyos datos sean "iguales" a los datos de referencia.

Se declarará de la siguiente manera :

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())

cmp toma dos void* y devuelve 0 cuando ambos parámetros son iguales.

Debe utilizar el archivo ft_list.h, que contendrá:

$>cat ft_list.h
typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;
$>
--------------------------------------------------------------------------------*/
