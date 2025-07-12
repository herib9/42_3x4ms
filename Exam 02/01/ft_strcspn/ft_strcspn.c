#include <unistd.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    int i = 0;
    int j;

    while (s[i])
    {
        j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return (i);
            j++;
        }
        i++;
    }
    return (i);
}

int	main(void)
{
	printf("%lu\n", ft_strcspn("hello123", "0123456789"));
	printf("%lu\n", strcspn("hello123", "0123456789"));
	printf("%lu\n", ft_strcspn("hellllo123", "gati"));
	printf("%lu\n", strcspn("hellllo123", "gati"));
}

// ejemplo: si *s es "hello123" y *reject es "0123456789", devuelve (i) que es 5.

/*
--------------------------------------------------------------------------------
Reproduce exactamente el comportamiento de la función strcspn (man strcspn).
(string complement span)

Básicamente, cuenta los caracteres de *s hasta encontrar uno que aparezca en 
*reject. Si no hay coincidencias, recorre *s y cuenta lo que mide.
--------------------------------------------------------------------------------
*/
