#include <unistd.h>

void	putnbr(int nb)
{
	if (nb > 9)
		putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

int	main(void)
{
	int	nb = 1;

	while(nb <= 100)
	{
		if (nb % 3 == 0 && nb % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (nb % 3 == 0)
			write(1, "fizz", 4);
		else if (nb % 5 == 0)
			write(1, "buzz", 4);
		else
			putnbr(nb);
		write(1, "\n", 1);
		nb++;
	}
}

/*
Assignment name  : fizzbuzz
Expected files   : fizzbuzz.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe un programa que imprima los números del 1 al 100, cada uno separado por 
un salto de línea.

Si el número es múltiplo de 3, imprime 'fizz' en su lugar.

Si el número es múltiplo de 5, imprime 'buzz' en su lugar.

Si el número es tanto múltiplo de 3 como múltiplo de 5, imprime 'fizzbuzz' en 
su lugar.

Ejemplos:

$>./fizzbuzz
1
2
fizz
4
buzz
fizz
7
8
fizz
buzz
11
fizz
13
14
fizzbuzz
[...]
97
98
fizz
buzz
$> 
--------------------------------------------------------------------------------
*/
