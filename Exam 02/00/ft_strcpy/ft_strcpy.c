#include <stdio.h>
#include <string.h>

char    *ft_strcpy(char *s1, char *s2)
{
	int	i = 0;
	
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	main()
{
	char	s1[59];
	char	*s2 = "hola";
	printf("%s\n", ft_strcpy(s1, s2));
	printf("%s\n", strcpy(s1, s2));
}

/*
Assignment name  : ft_strcpy
Expected files   : ft_strcpy.c
Allowed functions: 
--------------------------------------------------------------------------------

Reproduce el comportamiento de la función strcpy (man strcpy).

Tu función debe ser declarada de la siguiente manera:

char    *ft_strcpy(char *s1, char *s2)

Copia el contenido de *s2 en *s1
--------------------------------------------------------------------------------
*/
