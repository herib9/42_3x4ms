#include <unistd.h>

void	wdmatch(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;

	while (s1[i] && s2[j])
	{
		if (s1[i] == s2[j])
			i++;
		j++;
	}
	if (s1[i] == '\0')
		write(1, &s1, i);
}

int main(int argc, char **argv)
{
	if (argc == 3)
		wdmatch(argv[1], argv[2]);
	write(1, "\n", 1);
}

/*
Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: 
--------------------------------------------------------------------------------

Escriba un programa que tome dos strings y verifique si es posible escriba el 
primer string con caracteres del segundo string, respetando el orden en que 
aparecen estos caracteres en el segundo string.

Si es posible, el programa muestra el string, seguido de un \n, de lo contrario
simplemente muestra un \n.

Si el numero de argumentos no es 2, el programa muestra un \n.

Ejemplos:

$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e\
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e\
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e\
quarante deux$
$>./wdmatch "error" "rrerrrfiiljdfxjyuifrrvcoojh" | cat -e\
$
$>./wdmatch | cat -e\
$
--------------------------------------------------------------------------------
*/
