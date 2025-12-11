#include <unistd.h>

void	hidenp(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	
	while (s1[i] && s2[j])
	{
		if(s1[i] == s2[j])
			i++;
		j++;
	}
	if (s1[i] == 0)
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
}

/*Assignment name  : hidenp
Expected files   : hidenp.c
Allowed functions: write
--------------------------------------------------------------------------------

Escriba un programa llamado hidenp que tome dos strings y muestre 1 seguido de 
una nueva línea si el primer string está oculta en el segundo, de lo contrario,
muestra 0 seguido de una nueva línea. 

Decimos que s1 está oculto en s2 si es posible encuentrar cada carácter de s1 
en s2, en el mismo orden en que aparecen en s1. Además, el string vacío está 
oculto en cualquier string. 

Si el número de parámetros no es 2, el programa muestra una nueva línea.

Ejemplos:

$>./hidenp "fgex.;" "tyf34gdgf;'ektufjhgdgex.;.;rtjynur6" | cat -e
1$
$>./hidenp "abc" "2altrb53c.sse" | cat -e
1$
$>./hidenp "abc" "btarc" | cat -e
0$
$>./hidenp | cat -e
$
$>
--------------------------------------------------------------------------------*/
