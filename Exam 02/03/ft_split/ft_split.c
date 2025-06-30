#include <unistd.h>

int	ft_separate(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

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
}
