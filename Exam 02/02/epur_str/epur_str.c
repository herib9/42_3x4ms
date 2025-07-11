#include <unistd.h>

void	epur_s(char *s)
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
				write(1, " ", 1);
			write(1, &s[i], 1);
			flag = 0;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_s(argv[1]);
	write(1, "\n", 1);
	return 0;
}

/*
Assignment name  : epur_str
Expected files   : epur_str.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome un string y muestre este string con exactamente un
espacio entre palabras, sin espacios ni tabulaciones ni al principio ni al 
final, seguido de un \n.

Una "palabra" se define como una parte de un string delimitada ya sea por 
espacios/tabulaciones, o por el principio/fin del string.

Si el número de argumentos no es 1, o si no hay palabras para mostrar, el
programa muestra \n.

Ejemplos:

$> ./epur_str "See? It's easy to print the same thing" | cat -e
See? It's easy to print the same thing$
$> ./epur_str " this        time it      will     be    more complex  . " | cat -e
this time it will be more complex .$
$> ./epur_str "No S*** Sherlock..." "nAw S*** ShErLaWQ..." | cat -e
$
$> ./epur_str "" | cat -e
$
$>

$> ./epur_str "vous voyez c'est facile d'afficher la meme chose" | cat -e
vous voyez c'est facile d'afficher la meme chose$
$> ./epur_str " seulement          la c'est      plus dur " | cat -e
seulement la c'est plus dur$
$> ./epur_str "comme c'est cocasse" "vous avez entendu, Mathilde ?" | cat -e
$
$> ./epur_str "" | cat -e
$
$>
--------------------------------------------------------------------------------
*/
