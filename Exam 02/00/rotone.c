#include <unistd.h>

void	rotone(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if ((s[i] >= 'a' && s[i] <= 'y') || (s[i] >= 'A' && s[i] <= 'Y'))
			s[i] += 1;
		else if (s[i] == 'z' || s[i] == 'Z')
			s[i] -= 25;
		write(1, &s[i], 1); 
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rotone(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/*Assignment name  : rotone
Expected files   : rotone.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome un string y lo muestre, reemplazando cada una de 
sus letras por la siguiente en orden alfabético.

'z' se convierte en 'a' y 'Z' se convierte en 'A'. El string permanece sin 
cambios.

La salida estará seguida de un \n.

Si el número de argumentos no es 1, el programa muestra \n.

Ejemplos:

$>./rotone "abc"
bcd
$>./rotone "Les stagiaires du staff ne sentent pas toujours tres bon." | cat -e
Mft tubhjbjsft ev tubgg of tfoufou qbt upvkpvst usft cpo.$
$>./rotone "AkjhZ zLKIJz , 23y " | cat -e
BlkiA aMLJKa , 23z $
$>./rotone | cat -e
$
$>
$>./rotone "" | cat -e
$
$>
--------------------------------------------------------------------------------*/
