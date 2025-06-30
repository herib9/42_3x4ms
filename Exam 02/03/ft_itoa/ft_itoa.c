#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int	i = 0;
	int	num = nbr;
	char *	result;

	if (nbr < 0)
	{
		i++;
		nbr = -nbr;
	}
	while (nbr > 1)
	{
		nbr /= 10;
		i++;
	}
	result = malloc(sizeof(char) * (i + 1));
	result[i] = '\0';
	if (num == 0)
		result[0] = '0';
	else if (num < 0)
	{
		i = i - 1;
		num = -num;
		while (i >= 1)
		{
			result[i] = '0' + (num % 10);
			num = num / 10;
			i--;
		}
		result[0] = '-';
	}
	else
	{
		i = i - 1;
		while (i >= -1)
		{
			result[i] = '0' + (num % 10);
			num = num / 10;
			i--;
		}
	}
	return (result);
}

#include <stdio.h>

int main(void)
{
	int n = 23;
	
	printf("%s\n", ft_itoa(n));
}

