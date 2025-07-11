int	ft_atoi_base(const char *str, int str_base)
{
	int	i = 0;
	int	n = 0;
	int	result = 0;
	int	sign = 1;

	//if (str_base <= 1 || str_base > 16)
        //return (0);
	if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                {
                        signo = -1;
                        i++;
                }
        }
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			n = str[i] - '0';
		else if (str[i] >= 'a' && str[i] <= 'f')
			n = str[i] - 'a' + 10; 
		else if (str[i] >= 'A' && str[i] <= 'F')
			n = str[i] - 'A' + 10;
		else
			break ;
		if (n >= str_base)
            		break;
		result = result * str_base + n;
		i++;
	}
	return (result * sign);
}

#include <stdio.h>

int main(void)
{
    // Pruebas base 2 (binario)
    printf("Base 2: %d\n", ft_atoi_base("101", 2));        // 5
    printf("Base 2: %d\n", ft_atoi_base("-101", 2));       // -5

   // Pruebas base 8 (octal)
    printf("Base 8: %d\n", ft_atoi_base("12", 8));         // 10
    printf("Base 8: %d\n", ft_atoi_base("-12", 8));        // -10

    // Pruebas base 10 (decimal)
    printf("Base 10: %d\n", ft_atoi_base("123", 10));      // 123
    printf("Base 10: %d\n", ft_atoi_base("-123", 10));     // -123

    // Pruebas base 16 (hexadecimal)
    printf("Base 16: %d\n", ft_atoi_base("1a", 16));       // 26
    printf("Base 16: %d\n", ft_atoi_base("1A", 16));       // 26
    printf("Base 16: %d\n", ft_atoi_base("-1A", 16));      // -26

    // Pruebas casos inválidos
    printf("Base 1: %d\n", ft_atoi_base("1", 1));          // 0
    printf("Base 17: %d\n", ft_atoi_base("1", 17));        // 0
    printf("Base 16 invalida: %d\n", ft_atoi_base("1G", 16)); // 1

    return (0);
}

/*
Assignment name  : ft_atoi_base
Expected files   : ft_atoi_base.c
Allowed functions: None
--------------------------------------------------------------------------------

Escribe una función que convierta el argumento del string str (base N <= 16)
a un entero (base 10) y lo devuelva.

Los caracteres reconocidos en la entrada son: 0123456789abcdef
Estos, por supuesto, deben recortarse según la base solicitada. Por ejemplo,
la base 4 reconoce "0123" y la base 16 reconoce "0123456789abcdef".

Las mayúsculas también deben ser reconocidas: "12fdb3" es lo mismo que "12FDB3".

Los signos negativos ('-') se interpretan solo si son el primer carácter del
string.

int	ft_atoi_base(const char *str, int str_base)
--------------------------------------------------------------------------------
*/
