unsigned char	reverse_bits(unsigned char octet)
{
	int	i = 7;
	unsigned char	result = 0;
	while (i >= 0)
	{
		result = (result << 1) | ((octet >> i) & 1);
		i--;
	}
	return (result);
}

unsigned char	reverse_bits(unsigned char octet)
{
	unsigned int	i = 8;
	unsigned char	r = 0;
	
	while (i--)
	{
		r = (r << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (r);
}

/*Ejemplo con octet = 2 (00000010):

i=7:
- octet >> 7 = 00000000 & 1 = 0
- result = 00000000 << 1 | 0 = 00000000

i=6:
- octet >> 6 = 00000000 & 1 = 0
- result = 00000000 << 1 | 0 = 00000000

...

i=1:
- octet >> 1 = 00000001 & 1 = 1
- result = 00000000 << 1 | 1 = 00000001

i=0:
- octet >> 0 = 00000010 & 1 = 0
- result = 00000001 << 1 | 0 = 00000010

Resultado final: 01000000 (64 en decimal)

Assignment name  : reverse_bits
Expected files   : reverse_bits.c
Allowed functions:
--------------------------------------------------------------------------------

Escriba una función que tome un byte, lo invierta, bit a bit (como en el 
ejemplo) y devuelva el resultado.

Tu función debe declararse como sigue:

unsigned char	reverse_bits(unsigned char octet)

Example:

  1 byte
_____________
 0100  0001
     ||
     \/
 1000  0010
--------------------------------------------------------------------------------*/
