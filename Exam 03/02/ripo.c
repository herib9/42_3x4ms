#include <stdio.h>

int	invalid(char *s)
{
	int i = 0;
	int open = 0;
	int close = 0;

	while (s[i])
	{
		if (s[i] == '(')
			open++;
		else if (s[i] == ')')
		{
			if (open > 0)
				open--;
			else
				close++;
		}
		i++;
	}
	return(open + close);
}

void	result(char *s, int remove, int del, int pos)
{
	if (remove == del && !invalid(s))
	{
		puts(s);
		return;
	}
	while (s[pos])
	{
		if(s[pos] == '(' || s[pos] == ')')
		{
			char c = s[pos];
			s[pos] = ' ';
			result(s, remove, del + 1, pos + 1);
			s[pos] = c;
		}
		pos++;
	}
}

int	main(int ac, char **av)
{
	if (ac == 2)
		generate_result(av[1], invalid(av[1]), 0, 0);
	return (ac != 2);
}