#include <stdlib.h>
#include <unistd.h>

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(char *s, int n)
{
	int i = 0;
	while (i < n - 1)
	{
		int j = i + 1;
		while (j < n)
		{
			if (s[i] > s[j])
				swap(&s[i], &s[j]);
			j++;						
		}
		i++;
	}
}

void perm(char *res, char *opc, int *used, int pos, int n)
{
	int	i = 0;
	if (pos == n)
	{
		write(1, res, n);
		write(1, "\n", 1);
		return;
	}
	while (i < n)
	{
		if (!used[i])
		{
			res[pos] = opc[i];
			used[i] = 1;
			perm(res, opc, used, pos + 1, n);
			used[i] = 0;
		}
		i++;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
		return 1;

	int i = 0;
	while (av[1][i])
		i++;
	int n = i;
	char *s = malloc(n + 1);
	char *res = malloc(n + 1);
	int *used = calloc(n, sizeof(int));
	i = 0;
	while (i < n)
		s[i] = av[1][i++];
	s[n] = 0;
	res[n] = 0;
	sort(s, n);
	perm(res, s, used, 0, n);

	free(s);
	free(res);
	free(used);
	return (0);
}
