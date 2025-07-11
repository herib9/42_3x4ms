#include <unistd.h>

void	sr(char *s, char *old, char *new)
{
	int	i = 0;

	while (s[i] && new[1] == '\0')
	{
		if (s[i] == *old)
			s[i] = *new;
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4)
		sr(argv[1], argv[2], argv[3]);
	write(1, "\n", 1);
	return (0);
}

/* otra forma seria

void	sr(char *s, char *old, char *new)
{
	int	i = 0;

	while (s[i] && new[1] == '\0')
	{
		if (s[i] == *old)
			write(1, new, 1);
		else
			write(1, &s[i], 1);
		i++;
	}
}*/

/*
Assignment name  : search_and_replace
Expected files   : search_and_replace.c
Allowed functions: write, exit
--------------------------------------------------------------------------------

Escribe un programa llamado search_and_replace que tome 3 argumentos, el primero
es un string en el cual reemplazar una letra (segundo argumento) por
otra (tercer argumento).

Si el número de argumentos no es 3, simplemente muestra un salto de línea.

Si el segundo argumento no está contenido en el primero (el string)
entonces el programa simplemente reescribe el string seguida de un salto de línea

Ejemplos:

$>./search_and_replace "Papache est un sabre" "a" "o"
Popoche est un sobre
$>./search_and_replace "zaz" "art" "zul" | cat -e
$
$>./search_and_replace "zaz" "r" "u" | cat -e
zaz$
$>./search_and_replace "jacob" "a" "b" "c" "e" | cat -e
$
$>./search_and_replace "ZoZ eT Dovid oiME le METol." "o" "a" | cat -e
ZaZ eT David aiME le METal.$
$>./search_and_replace "wNcOre Un ExEmPle Pas Facilw a Ecrirw " "w" "e" | cat -e
eNcOre Un ExEmPle Pas Facile a Ecrire $
--------------------------------------------------------------------------------
*/
