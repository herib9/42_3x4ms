#include <unistd.h>

void	ftunion(char *s1, char *s2)
{
	int	i = 0;

	while(s1[i])
	{
		unsigned char c = s1[i];
		if (s2[c] == 0)
		{
			write(1, &c, 1);
			s2[c] = 1;
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	char	s2[256] = {};

	if (ac == 3)
	{
		ftunion(av[1], s2);
		ftunion(av[2], s2);
	}
	write(1, "\n", 1);
}

/*Assignment name  : union
Expected files   : union.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome dos strings y muestre, sin duplicados, los
caracteres que aparecen en alguno de los dos strings.

La visualización será en el orden en que aparecen los caracteres en la línea de
comandos y será seguida de un \n.

Si el número de argumentos no es 2, el programa mostrará \n.

Ejemplos:

$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
zpadintoqefwjy$
$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
df6vewg4thras$
$>./union "rien" "cette phrase ne cache rien" | cat -e
rienct phas$
$>./union | cat -e
$
$>
$>./union "rien" | cat -e
$
$>
--------------------------------------------------------------------------------*/
