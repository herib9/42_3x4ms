#include <string.h>
#include <unistd.h>

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t	i = 0;
	size_t	j;

	while (s[i])
	{
		j = 0;
		while (accept[j])
		{
			if (accept[j] == s[i])
				break;
			j++;
		}
		if (!accept[j])
			return (i);
		i++;
	}
	return (i);
}

#include <stdio.h>

int	main(void)
{
	printf("%lu\n", ft_strspn("hello123", "helo"));
	printf("%lu\n", strspn("hello123", "helo"));
}
