#include <unistd.h>

void	repeat_alpha(char *s)
{
	int	i = 0;
	int	repeat = 0;

	while (s[i])
	{
		if (s[i] >= 65 && s[i] <= 90)
			repeat = s[i] - 64;
		else if (s[i] >= 97 && s[i] <= 122)
			repeat = s[i] - 96;
		else
			repeat = 1;
		while (repeat > 0)
		{
			write(1, &s[i], 1);
			repeat++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		repeat_alpha(argv[1]);
	write(1, "\n", 1);
}


/*void	repeat_alpha(char *c)
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
}*/
