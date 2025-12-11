#include <unistd.h>

void	expand_str(char *s)
{
	int	flag = 0;
	int	i = 0;

	while (s[i] < 33)
		i++;
	while (s[i])
	{
		if (s[i] < 33)
			flag = 1;
		else
		{
			if (flag)
				write(1, "   ", 3);
			write(1, &s[i], 1);
			flag = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
}

/*Assignment name  : expand_str
Expected files   : expand_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome un string y lo muestre con exactamente tres 
espacios entre cada palabra, sin espacios ni tabulaciones ni al principio ni al
final, seguido de un salto de línea.

Una palabra es una sección de string delimitada ya sea por espacios/tabulaciones,
o por el principio/fin del string.

Si el número de parámetros no es 1, o si no hay palabras, simplemente muestra
un salto de línea.

Ejemplos:

$> ./expand_str "See? It's easy to print the same thing" | cat -e
See?   It's   easy   to   print   the   same   thing$
$> ./expand_str " this        time it      will     be    more complex  " | cat -e
this   time   it   will   be   more   complex$
$> ./expand_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./expand_str "" | cat -e
$
$>

$> ./expand_str "vous   voyez   c'est   facile   d'afficher   la   meme   chose" | cat -e
vous   voyez   c'est   facile   d'afficher   la   meme   chose$
$> ./expand_str " seulement          la c'est      plus dur " | cat -e
seulement   la   c'est   plus   dur$
$> ./expand_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./expand_str "" | cat -e
$
$>
--------------------------------------------------------------------------------*/
