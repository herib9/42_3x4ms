#include <stdio.h>

char    *ft_strrev(char *str)
{
	char	temp[256];
	int	i = 0;
	int 	j = 0;
	
	while (str[i])
		i++;
	i--;
	while (i >= 0)
	{
		temp[j] = str[i];
		i--;
		j++;
	}
	//temp[j] = '\0';
	str = temp;
	return (str);
}

char	*ft_strrev(char *s)
{
	int	i = 0;
	int	len = 0;
	int	temp;

	while (s[i])
		i++;
	i--;
	while (i > len)
	{
		temp = s[len];
		s[len] = s[i];
		s[i] = temp;
		len--;
		i++;
	}
	return (s);
}

int main(void)
{
	char *str = "hola";

	printf("str antes: %s\n", str);

	str = ft_strrev(str);

	printf("str despues: %s\n", str);
	return (0);
}

/*
--------------------------------------------------------------------------------
strrev invierte string al completo letra a letra, usando para ello una temporal
en la cual almacenaremos el string que luego pasaremos de nuevo a str para 
devolverlo
--------------------------------------------------------------------------------
*/
