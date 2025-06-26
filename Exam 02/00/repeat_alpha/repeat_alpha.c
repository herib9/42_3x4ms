#include <unistd.h>

void	repeat_alpha(char *c)
{
	int i;
	int j;

	i = 0;
	while (*c)
	{
		if (*c >= 65 && *c <= 90)
			i = *c - 64;
		else if (*c >= 97 && *c <= 122)
			i = *c - 96;
		else
			i = 1;
		j = 0;
		while (j < i)
		{
			write(1, c, 1);
			j++;
		}
		c++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
}


void	repeat_alpha(char *c)
{
	int repeat = 0;

	while (*c)
	{
		if (*c >= 65 && *c <= 90)
			repeat = *c - 64;
		else if (*c >= 97 && *c <= 122)
			repeat = *c - 96;
		else
			repeat = 1;
		while (repeat > 0)
		{
			write(1, c, 1);
			repeat--;
		}
		c++;
	}
}