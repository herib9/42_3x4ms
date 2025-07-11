#include <unistd.h>

void	rot(char *s)
{
	int	i = 0;
	
	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'm') || (s[i] >= 'A' && s[i] <= 'M'))
			s[i] += 13;
		else if ((s[i] >= 'n' && s[i] <= 'z') || (s[i] >= 'N' && s[i] <= 'Z'))
			s[i] -= 13;
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rot(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*
Assignment name  : rot_13
Expected files   : rot_13.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome un string y lo muestre, reemplazando cada una de
sus letras por la letra 13 espacios adelante en orden alfabético.

'z' se convierte en 'm' y 'Z' se convierte en 'M'. El caso permanece sin cambios

La salida estará seguida de un salto de línea.

Si el número de argumentos no es 1, el programa muestra un salto de línea.

Ejemplos:

$>./rot_13 "abc"
nop
$>./rot_13 "My horse is Amazing." | cat -e
Zl ubefr vf Nznmvat.$
$>./rot_13 "AkjhZ zLKIJz , 23y " | cat -e
NxwuM mYXVWm , 23l $
$>./rot_13 | cat -e
$
$>
$>./rot_13 "" | cat -e
$
$>
--------------------------------------------------------------------------------
*/
