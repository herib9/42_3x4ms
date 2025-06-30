#include <unistd.h>

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}
/*
  devuelve 1 si hay espacio o tabulador
  devuelve 0 si no
*/
int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		int i = 0;
		while (argv[1][i] && is_space(argv[1][i]))
			++i;
		while (argv[1][i] && !is_space(argv[1][i]))
			++i;
		while (argv[1][i] && is_space(argv[1][i]))
                        ++i;
		while (argv[1][i])
		{
			while (argv[1][i] && is_space(argv[1][i]))
			{
				++i;
			}
			while (argv[1][i] && !is_space(argv[1][i]))
			{
				write(1, &argv[1][i], 1);
				++i;
			}
			write(1, " ", 1);
		}
		i = 0;
		while (argv[1][i] && is_space(argv[1][i]))
			++i;
		while (argv[1][i] && !is_space(argv[1][i]))
		{
			write(1, &argv[1][i], 1);
			++i;
		}
	}
	write(1, "\n", 1);
}

/* verifica que exista argumento (se paso un string)
* declara indice i para recorrer string
* 1º while: mientras argumento exista y haya espacios al principio los salta todos
* 2º while: recorre la primera palabra sin guardarla ni imprimirla, solo avanza
* 3º while: salta posibles espacios despues de la primera palabra
* WHILE principal: mientras exista el argumento
* 1º while: salta espacios entre palabras
* 2º while: escribe letra a letra la siguiente palabra
* write espacio despues de cada palabra
** hasta aqui hemos imprimido todas las palabras menos la primera
* reiniciamos i a 0
* 1º while: salta espacios al inicio
* 2º while: imprime la primera palabra letra a letra
* termina con un salto de linea
