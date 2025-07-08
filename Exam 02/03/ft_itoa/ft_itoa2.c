#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr) 
{
	int	num = nbr;
	int	len = 0;
	char *	result;

	if (nbr <= 0)
		len++;
	while (num) 
	{
	        num = num / 10;		// num /= 10
	        len++;
	}
	result = malloc(len + 1);
	//if (result == NULL) 
	//        return NULL;
	result[len] = '\0';
	if (nbr == 0)
		result[0] = '0';
	if (nbr < 0)
	{
	        result[0] = '-';
	        nbr = -nbr;
	}
	len--;
	while (nbr) 
	{
	        result[len] = nbr % 10 + '0';
	        nbr /= 10;
	        len--;
	}	
	return (result);
}

int main(void)
{
	int n = -123;
	printf("%s\n", ft_itoa(n));
}

