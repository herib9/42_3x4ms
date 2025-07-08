#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int pgcd(char *none, char *ntwo)
{
	int n1 = atoi(none);
	int n2 = atoi(ntwo);
	int i = n2;
	while (i != 1)
	{
		if ((n1 % i == 0) && (n2 % i == 0))
			return(i);
		i--;
	}
	return(i);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
		printf("%i\n", pgcd(argv[1], argv[2]));
	return(0);
}