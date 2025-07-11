#include <unistd.h>

void	s2c(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] == '_')
		{
			i++;
			s[i] -= 32;
			write(1, &s[i], 1);
		}
		else
			write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		s2c(av[1]);
	write(1, "\n", 1);
}

/*
Assignment name  : snake_to_camel
Expected files   : snake_to_camel.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Escribe un programa que tome un solo string en formato snake_case y lo convierta
en un string en formato lowerCamelCase.

Un string en snake_case es un string donde cada palabra está en minúsculas,
separadas por un guion bajo "_".

Un string en lowerCamelCase es un string donde cada palabra comienza con una 
letra mayúscula excepto la primera.

Ejemplos:

$>./snake_to_camel "here_is_a_snake_case_word"
hereIsASnakeCaseWord
$>./snake_to_camel "hello_world" | cat -e
helloWorld$
$>./snake_to_camel | cat -e
$
--------------------------------------------------------------------------------
*/
