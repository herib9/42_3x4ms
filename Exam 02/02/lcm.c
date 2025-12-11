#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
        int     temp;
        int     n = a * b;
        
        if ((int)a < 0 || (int)b < 0)
                return (0);
        if (a == 0 || b == 0)
                return (0);
        while(b != 0)   
        {       
                temp = b;
                b = a % b;
                a = temp;
        }       
        return (n / a);
}

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}    

int     main()
{       
        printf("%i\n", lcm(-1, 2932));
        printf("%i\n", lcm(3, 5));
}

/*(lcm)ft_minimo_comun_multiplo(a, b) = (ft_absolute)ft_valor_absoluto(a * b) / (hcf)ft_maximo_comun_divisor(a, b)

lcm(a, b) = (|a * b|) / (hcf(a, b))
producto = a * b

Assignment name  : lcm
Expected files   : lcm.c
Allowed functions:
--------------------------------------------------------------------------------

Escribe una función que tome dos enteros sin signo como parámetros y devuelva
el Mínimo Común Múltiplo (LCM) calculado de esos parámetros.

El LCM (Mínimo Común Múltiplo) de dos enteros no nulos es el menor entero 
positivo divisible por ambos enteros.

Un LCM se puede calcular de dos maneras:

- Puedes calcular todos los múltiplos de cada entero hasta que tengas un 
múltiplo común diferente de 0.

- Puedes usar el HCF (Mayor Común Factor) de estos dos enteros y calcular de 
la siguiente manera:

	LCM(x, y) = | x * y | / HCF(x, y)

  | x * y | significa "Valor absoluto del producto de x por y".

Si al menos uno de los enteros es nulo, el LCM es igual a 0.

Tu función debe tener el siguiente prototipo:

unsigned int    lcm(unsigned int a, unsigned int b)
--------------------------------------------------------------------------------*/
