#include <stdlib.h>

char	**ft_split(char *str)
{
	char **split = malloc (sizeof(char *) * 10000);
	int	i = 0;
	int	j = 0;

	while (*str)
	{
		split[i] = malloc (sizeof(char) * 10000);
		j = 0;
		while (*str < 33 && *str != '\0')
			str++;
		if (*str == '\0')
			break ;
		while (*str > 33)
		{
			split[i][j] = *str;
			j++;
			str++;
		}
		split[i][j] = '\0';
		i++;
	}
	split[i] = NULL;
	return (split);
}


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
		//if(!word[i])
		//	return (NULL);
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
