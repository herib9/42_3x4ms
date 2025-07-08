#include <unistd.h>

void	inter(char *s1, char *s2)
{
	int	i = 0;
	int	j;
	
	while (s1[i])
	{
		j = 0;
		while (j < i && s1[j] != s1[i])		
			j++;
		if (j == i)
		{
			j = 0;
			while (s2[j] && s2[j] != s1[i])
				j++;
			if (s2[j])
				write(1, &s1[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}


/*
el 2º while comprueba que una letra en s1 no esté repetida
si j == i no esta repetida
mientras s2[j] exista y s2[j] sea diferente a s1[i]
avanza j
si s2[j] no es el final, quiere decir que hubo coincidencia
escribe s1[i] y avanza
*/  
