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

/*int main(int argc, char **argv)
{
    if (argc == 3)
        ft_strcspn(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}*/

int	main(void)
{
	printf("%lu\n", ft_strcspn("hello123", "e0123456789"));
	printf("%lu\n", strcspn("hello123", "0123456789"));
}

/*ejemplo: si *s es "hello123" y *reject es "0123456789", devuelve (i) que es 5.
Básicamente, cuenta los caracteres de *s hasta encontrar uno que aparezca en *reject.
Si no hay coincidencias, recorre *s y cuenta lo que mide.*/
