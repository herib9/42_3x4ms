#include <unistd.h>

void	am(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] >= 97 && s[i] <= 122)
			s[i] =  122 - (s[i] - 97);
		if (s[i] >= 65 && s[i] <= 90)
			s[i] = 90 - (s[i] - 65);
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		am(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*Assignment name  : alpha_mirror
Expected files   : alpha_mirror.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa llamado alpha_mirror que tome un string y muestre este 
string después de reemplazar cada carácter alfabético por el carácter alfabético
opuesto, seguido de una nueva línea.

'a' se convierte en 'z', 'Z' se convierte en 'A'
'd' se convierte en 'w', 'M' se convierte en 'N'

y así sucesivamente.

No se cambia el ninguna de las letras.

Si el número de argumentos no es 1, muestra solo una nueva línea.

Ejemplos:

$>./alpha_mirror "abc"
zyx
$>./alpha_mirror "My horse is Amazing." | cat -e
Nb slihv rh Znzarmt.$
$>./alpha_mirror | cat -e
$
$>
--------------------------------------------------------------------------------*/
