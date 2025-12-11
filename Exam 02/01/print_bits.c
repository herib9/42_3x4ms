#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int	i = 7;

	while (i >= 0)
	{
		if ((octet >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

void print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;
	while(i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit,1);
	}
}

/*	int	main()
	{
		print_bits(8);
	}

Assignment name  : print_bits
Expected files   : print_bits.c
Allowed functions: write
--------------------------------------------------------------------------------

Escribe una función que tome un byte y lo imprima en binario SIN UN SALTO DE 
LÍNEA AL FINAL.

Tu función debe ser declarada de la siguiente manera:

void	print_bits(unsigned char octet)

Por ejemplo, si pasas 2 a print_bits, imprimirá "00000010"
--------------------------------------------------------------------------------*/
