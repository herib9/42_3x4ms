#include "stdlib.h"
#include "unistd.h"

void ft_putnbr(int nb)
{
	if (nb > 9)
		ft_putnbr(nb / 10);
	write(1, &"0123456789"[nb % 10], 1);
}

int is_valid_pos(int *table, int x, int y)
{
	int i = 0;
	while (i < y)
	{
		if ((x == table[i]) || (x - y) == (table[i] - i) || (x + y) == (table[i] + i))
			return (0);
		i++;
	}
	return (1);
}

void print_table(int *table, int size)
{
	int i = 0;

	while (i < size)
		ft_putnbr(table[i++]);
	write(1, "\n", 1);
}

void n_queen(int *table, int y, int size)
{
	int x = 0;
	if (y == size)
		return (print_table(table, size));
	while(x < size)
	{
		if (is_valid_pos(table, x, y))
		{
			table[y] = x;
			n_queen(table, y + 1, size);
		}
		x++;
	}
}

int main (int ac, char **av)
{
	if (ac < 2)
		return(write(1, "\n", 1), 0);
	int size = atoi(av[1]);
	int table[size];
	n_queen(table, 0, size);
	return (0);
}
