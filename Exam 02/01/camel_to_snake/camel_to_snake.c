#include <unistd.h>

void	c2s(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			write(1, "_", 1);
			s[i] += 32;
		}
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		c2s(av[1]);
	write(1, "\n", 1);
}

/*
Assignment name  : camel_to_snake
Expected files   : camel_to_snake.c
Allowed functions: malloc, free, realloc, write
--------------------------------------------------------------------------------

Escribe un programa que tome un string único en formato lowerCamelCase y lo
convierta en un string en formato snake_case.

Un string en lowerCamelCase es un string donde cada palabra comienza con una 
letra mayúscula excepto la primera.

Un string en snake_case es un string donde cada palabra está en minúsculas,
separadas por un guion bajo "_".

Ejemplos:
$>./camel_to_snake "hereIsACamelCaseWord"
here_is_a_camel_case_word
$>./camel_to_snake "helloWorld" | cat -e
hello_world$
$>./camel_to_snake | cat -e
$
--------------------------------------------------------------------------------
*/
