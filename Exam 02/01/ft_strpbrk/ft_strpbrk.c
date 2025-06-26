char	*ft_strpbrek(const char *s1, const char *s2)
{
	int	i = 0;
	int	j;
	
	if (!s1 || !s2)
		return (0);
	while (s2[i])
	{
		j = 0;
		while (s1[j])
		{
			if (s2[i] == s1[j])
				return (&s1[1]);
			++j;
		}
		++i;
	}
	return(0);
}
