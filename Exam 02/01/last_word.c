#include <unistd.h>

void	lw(char *s)
{
	int	i = 0;

	while (s[i])
		i++;
	i--;
	while (s[i] && s[i] <= 32)
		i--;
	while (s[i] > 32)
		i--;
	i++;
	while (s[i] > 32)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		lw(av[1]);
	write(1, "\n", 1);
}

/*Assignment name  : last_word
Expected files   : last_word.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome un string y muestre su última palabra seguida de 
un \n.

Una palabra es una sección de string delimitada por espacios/tabulaciones o por
el inicio/fin del string.

Si el número de parámetros no es 1, o no hay palabras, muestra una nueva línea.

Ejemplos:

$> ./last_word "FOR PONY" | cat -e
PONY$
$> ./last_word "this        ...       is sparta, then again, maybe    not" | cat -e
not$
$> ./last_word "   " | cat -e
$
$> ./last_word "a" "b" | cat -e
$
$> ./last_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
--------------------------------------------------------------------------------*/
