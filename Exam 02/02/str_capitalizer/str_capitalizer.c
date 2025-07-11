#include <unistd.h>

void	cap(char *s)
{
	int	i = 0;

	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
		if ((s[i] >= 'a' && s[i] <= 'z') && (s[i - 1] <= 32 || s[i - 1] == 0))
			s[i] -= 32;
		write(1, &s[i], 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	int	i = 1;
	
	if (ac == 1)
		write(1, "\n", 1);
	while (ac > i)
	{
		cap(argv[i]);
		write(1, "\n", 1);
		i++;
	}
}

/*
Assignment name  : str_capitalizer
Expected files   : str_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome uno o varios strings y, para cada argumento,
ponga en mayuscula el primer carácter de cada palabra (Si es una letra, 
obviamente), ponga el resto en minúsculas, y muestre el resultado en la salida 
estándar, seguido de un \n.

Una "palabra" se define como una parte de un string delimitada por 
espacios/tabulaciones o por el inicio/fin del string. Si una palabra tiene solo 
una letra, debe ser capitalizada.

Si no hay argumentos, el programa debe mostrar \n.

Ejemplos:

$> ./str_capitalizer | cat -e
$
$> ./str_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A First Little Test$

$> ./str_capitalizer "__SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
__second Test A Little Bit   Moar Complex$
   But... This Is Not That Complex$
     Okay, This Is The Last 1239809147801 But Not    The Least    T$
$>
--------------------------------------------------------------------------------
*/
