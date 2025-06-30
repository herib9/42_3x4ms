#include <unistd.h>

void	rws(char *s)
{
	int	i = 0;
	int	start = 0;
	int	end = 0;

	while (s[i] == ' ' && s[i] == '\t')
		i++;
	while (s[i])
		i++;
	i--;
	while (i >= 0)
	{
		while (i >= 0 && (s[i] == ' ' || s[i] == '\t'))
			i--;
		end = i;
		while (i >= 0 && s[i] != ' ' && s[i] != '\t' && s[i] != '\0')
			i--;
		start = i + 1;
		while (start <= end)
		{
			write(1, &s[start], 1);
			start++;
		}
		if (s[i] > 1)
			write(1, " ", 1);
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		rws(av[1]);
	write(1, "\n", 1);
}



			

