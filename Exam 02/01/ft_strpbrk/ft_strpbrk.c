#include <stdio.h>
#include <string.h>
#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i = 0;
	int	j;
	
	while (s1[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s2[j] == s1[i])
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return(NULL);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		printf("%s\n", strpbrk(av[1], av[2]));
		printf("%s\n", ft_strpbrk(av[1], av[2]));
	}
}

/*
--------------------------------------------------------------------------------
Reproduce el comportamiento de la función strpbrk (string pointer break)
(man strpbrk).

Busca la primera ocurrencia en s1 de cualquier carácter que esté en s2
Devuelve un puntero a la posición donde encontró la primera coincidencia
Si no encuentra ninguna coincidencia, devuelve NULL.
--------------------------------------------------------------------------------
*/
