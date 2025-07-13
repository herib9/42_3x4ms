#include <unistd.h>

void	rostring(char *s)
{
	int	i = 0;
	int	start = 0;
	int	end = 0;
	int	word = 0;
	int	space = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	start = i;
	while (s[i] > 32)
		i++;
	end = i - 1;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t')
			space = 1;
		else
		{
			if (space == 1)
			{

				write(1, " ", 1);
				space = 0;
			}
			word = 1;
			write(1, &s[i], 1);
		}
		i++;
	}
	if (s[i] == 0 && word == 1)
		write(1, " ", 1);
	while (start <= end)
	{
		write(1, &s[start], 1);
		start++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rostring(av[1]);
	write(1, "\n", 1);
}

/*
--------------------------------------------------------------------------------
Escribe un programa que tome una cadena y muestre esta cadena después de rotarla
una palabra hacia la izquierda.

Así, la primera palabra se convierte en la última, y las demás se mantienen en 
el mismo orden.

Una "palabra" se define como una parte de una cadena delimitada por 
espacios/tabulaciones, o por el inicio/fin de la cadena.

Las palabras estarán separadas por solo un espacio en la salida.

Si hay menos de un argumento, el programa muestra \n.

Ejemplos:

$>./rostring "abc   " | cat -e
abc$
$>
$>./rostring "Que la      lumiere soit et la lumiere fut"
la lumiere soit et la lumiere fut Que
$>
$>./rostring "     AkjhZ zLKIJz , 23y"
zLKIJz , 23y AkjhZ
$>
$>./rostring "first" "2" "11000000"
first
$>
$>./rostring | cat -e
$
$>
--------------------------------------------------------------------------------
*/
