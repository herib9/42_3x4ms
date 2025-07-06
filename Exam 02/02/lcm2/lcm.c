#include <stdio.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
        int     temp;
        int     r = a * b;
        
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
        return (r / a);
}       

int     main(void)
{       
        printf("%i\n", lcm(-1, 2932));
        printf("%i\n", lcm(3, 5));
}

//(lcm)ft_minimo_comun_multiplo(a, b) = (ft_absolute)ft_valor_absoluto(a * b) / (hcf)ft_maximo_comun_divisor(a, b)
//lcm(a, b) = (|a * b|) / (hcf(a, b))
//producto = a * b

