#include <stdio.h>

char    *ft_strrev(char *str)
{
	char	temp[255];
	int	i = 0;
	int 	j = 0;
	
	while (str[i])
		i++;
	i--;
	printf("i : %d\n", i);
	while (i >= 0)
	{
		temp[j] = str[i];
		i--;
		j++;
	}
	temp[j] = '\0';
	str = temp;
	return (str);
}

int main(void)
{
	char *str = "hola";

	printf("str antes: %s\n", str);

	str = ft_strrev(str);

	printf("str despues: %s\n", str);
	return (0);
}
