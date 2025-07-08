int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

#include <stdio.h>
int main (void)
{
	char  *s = "paquete";
	int i = 0;
	i = ft_strlen(s);
	printf("%d\n", i);
}
