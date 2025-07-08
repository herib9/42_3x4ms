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


/*int	ft_separate(char c)
	return (c == ' ' || c == '\t' || c == '\n');

int	ft_count(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while(s[i])
	{
		while (s[i] && ft_separate(s[i]))
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && !ft_separate(s[i]))
				i++;
		}
	}
	return (count);
}	

int	ft_word_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && !ft_separate(s[i])
		i++;
	return (i);
}

char	*ft_copy_word(char *s)
{
	int	i;
	char	*str;
	int	len;

	i = 0;
	len = ft_word_len(s);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return NULL;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char *s)
{
	int	i;
	char **split;

	i = 0;
	split = malloc(sizeof(char *) * (ft_count[s] + 1));
	if (!split)
		return NULL;
	while (*s)
	{
		while (*s && ft_separate(*s))
			s++;
		if (*s)
		{
			split[i] = ft_copy_word(s);
			i++;
			while (*s && !ft_separate(*s))
				s++;
		}
	}
	split[i] = NULL;
	return (split);
}*/
