#include <stdio.h>
#include <unistd.h>

char	*rev(char *s)
{
	int	i = 0;
	int	len = 0;
	int	temp;
	
	while (s[len])
		len++;
	len--;
	while (i < len)
	{
		temp = s[i];
		s[i] = s[len];
		s[len] = temp;
		i++;
		len--;
	}
	return (s);
}

/*int	main()
{
	char	s[] = "hola";
	printf("%s\n", rev(s));
}

int	main(int ac, char **av)
{
	int	i = 0;

	if (ac == 2)
	{
		rev(av[1]);
		while(av[1][i])
		{
			write(1, &av[1][i], 1);
			i++;
		}
	}	
	write(1, "\n", 1);
}*/

/*
Assignment name  : rev_print
Expected files   : rev_print.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome un string y muestre el string en orden inverso
seguido de un salto de línea.

Si el número de parámetros no es 1, el programa muestra un salto de línea.

Ejemplos:

$> ./rev_print "zaz" | cat -e
zaz$
$> ./rev_print "dub0 a POIL" | cat -e
LIOP a 0bud$
$> ./rev_print | cat -e
$
--------------------------------------------------------------------------------
*/
