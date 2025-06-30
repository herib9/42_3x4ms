#include "flood_fill.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void  flood_fill(char **tab, t_point size, t_point begin)
{
	t_point p;
	char c;
	
	c = tab[begin.y][begin.x];
	tab[begin.y][begin.x] = 'F';
	if (begin.y > 0 && tab[begin.y - 1][begin.x] == c)
	{
		p.x = begin.x;
		p.y = begin.y - 1;
		flood_fill(tab, size, p);
	}
	if ((begin.y < (size.y - 1)) && tab[begin.y + 1][begin.x] == c)
	{
		p.x = begin.x;
		p.y = begin.y + 1;
		flood_fill(tab, size, p);
	}
	if (begin.x > 0 && tab[begin.y][begin.x - 1] == c)
	{
		p.x = begin.x - 1;
		p.y = begin.y;
		flood_fill(tab, size, p);
	}
	if ((begin.x < (size.x - 1)) && tab[begin.y][begin.x + 1] == c)
	{
		p.x = begin.x + 1;
		p.y = begin.y;
		flood_fill(tab, size, p);
	}
}

// Función auxiliar para imprimir el mapa
void print_map(char **map, t_point size)
{
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
			printf("%c ", map[y][x]);
		printf("\n");
	}
}

int main(void)
{
	// Definimos el mapa manualmente
	char *map[] = {
		"AAAAA",
		"ABBAA",
		"ABBAA",
		"AAAAA"
	};

	// Convertimos cada línea en un array modificable (strdup)
	char **tab = malloc(sizeof(char *) * 4);
	for (int i = 0; i < 4; i++)
	{
		tab[i] = strdup(map[i]); // strdup copia las cadenas para poder modificarlas
	}

	t_point size = {5, 4};      // 5 columnas, 4 filas
	t_point begin = {1, 1};     // Empezamos en la 'B' central

	printf("Mapa antes de flood_fill:\n");
	print_map(tab, size);

	flood_fill(tab, size, begin);

	printf("\nMapa después de flood_fill:\n");
	print_map(tab, size);

	// Liberamos memoria
	for (int i = 0; i < 4; i++)
		free(tab[i]);
	free(tab);

	return 0;
}
