#include <unistd.h>

void    rstr(char *s)
{
	int	i = 0;
	
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] += 32;
        if ((s[i] >= 'a' && s[i] <= 'z') && (s[i + 1] <= 32 || s[i + 1] == '\0'))
			s[i] -= 32;
        write(1, &s[i], 1);
        i++;
	}
}

int     main(int ac, char **av)
{
        int     i = 1;

        if (ac == 1)
                 write(1, "\n", 1);
        while (i < ac)
        {
                rstr(av[i]);
                write(1, "\n", 1);
                i++;
        }
}

/*
Assignment name  : rstr_capitalizer
Expected files   : rstr_capitalizer.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que tome uno o más strings y, para cada argumento, ponga el
último carácter que es una letra de cada palabra en mayúscula y el resto en
minúscula, luego muestra el resultado seguido de un \n.

Una palabra es una sección de un string delimitada por espacios/tabulaciones o 
el inicio/final del string. Si una palabra tiene una sola letra, debe ser 
capitalizada.

Una letra es un carácter en el conjunto [a-zA-Z]

Si no hay parámetros, muestra \n.

Ejemplos:

$> ./rstr_capitalizer | cat -e
$
$> ./rstr_capitalizer "a FiRSt LiTTlE TESt" | cat -e
A firsT littlE tesT$

$> ./rstr_capitalizer "SecONd teST A LITtle BiT   Moar comPLEX" "   But... This iS not THAT COMPLEX" "     Okay, this is the last 1239809147801 but not    the least    t" | cat -e
seconD tesT A littlE biT   moaR compleX$
   but... thiS iS noT thaT compleX$
     okay, thiS iS thE lasT 1239809147801 buT noT    thE leasT    T$
$>
--------------------------------------------------------------------------------
*/
