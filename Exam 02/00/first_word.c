#include <unistd.h>

void	fw(char *s)
{
	int	i = 0;

	while (s[i] <= 32)
		i++;
	while (s[i] != 32 && s[i] != 9)
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fw(argv[1]);
	write(1, "\n", 1);
	return (0);
}


/*Assignment name  : first_word
Expected files   : first_word.c
Allowed functions: write
--------------------------------------------------------------------------------
Escribe un programa que tome un string y muestre su primera palabra, seguida de 
un salto de línea.

Una palabra es una sección de una cadena delimitada por espacios/tabulaciones o 
por el inicio/fin de la cadena.

Si el número de parámetros no es 1, o si no hay palabras, simplemente muestra
un salto de línea.

Ejemplos:

$> ./first_word "FOR PONY" | cat -e
FOR$
$> ./first_word "this        ...       is sparta, then again, maybe    not" | cat -e
this$
$> ./first_word "   " | cat -e
$
$> ./first_word "a" "b" | cat -e
$
$> ./first_word "  lorem,ipsum  " | cat -e
lorem,ipsum$
$>
--------------------------------------------------------------------------------*/
