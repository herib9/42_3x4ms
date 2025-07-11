#include <unistd.h>

void	repeat_alpha(char *s)
{
	int	i = 0;
	int	repeat = 0;

	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			repeat = s[i] - 64;
		else if (s[i] >= 97 && s[i] <= 122)
			repeat = s[i] - 96;
		else
			repeat = 1;
		while (repeat > 0)
		{
			write(1, &s[i], 1);
			repeat--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
}

/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa llamado repeat_alpha que tome un string y lo muestre
repitiendo cada carácter alfabético tantas veces como su índice alfabético,
seguido de un salto de línea.

'a' se convierte en 'a', 'b' se convierte en 'bb', 'e' se convierte en 'eeeee'...

El string permanece sin cambios.

Si el número de argumentos no es 1, solo muestra un salto de línea.

Ejemplos:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
--------------------------------------------------------------------------------
*/
