#include <unistd.h>
#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int	result = 0;
	int	i = 0;
	
	if (len == 0)
		return (0);
	
	while (i < len)
	{
		if (tab[i] > result)
			result = tab[i];
		i++;
	}
	return(result);
}

int	main(void)
{
	int	tab[] = {12, 2, 6, 14};
	int	len = 3;
	
	printf("%i\n", max(tab, len));
	return (0);
}

/*
	argv[0][2] ---> char
	argv[1] ---> char *



	char *argv2;

	argv2[0] -----> char c; 

	[ "hola ana", "que tal", "bien", NULL ] -----> char **matrix
	tengo 3 punteros dentro de mi doble puntero
	
	matrix[0] ---> char *cero ---> "hola ana"
	tengo 8 char dentro de mi puntero cero
	
	matrix[1] ---> char *uno ---> "que tal"
	tengo 7 char dentro de mi puntero uno
	
	matrix[2] ---> char *dos ---> "bien"
	tengo 4 char dentro de mi puntero dos

	matrix[0][2] ---> char ---> 'l'
	el caracter en la posicion 2 del puntero 0 de mi doble puntero

	"hola herib" ----> char *str
	tengo 10 char dentro de mi puntero
	str[7] ---> char ---> 'r'


	{ [ "hola", "ana" ] , [ "que tal", "herib" ] } ---> char ***triple
	
	triple[0] ---> char **doble_cero
	triple[0][1] ---> char *puntero_uno_del_doble_cero
	triple[0][1][2] ---> char 'a'

	"hola herib me quiero ir ya jejeje" ---> char *puntero
	puntero[0] ---> char ---> 'h'


	( { [ "hola", "ana" ] , [ "que tal", "herib" ] } , 
	  { [ "hola", "ana" ] , [ "que tal", "herib" ] } ,
	  { [ "hola", "ana" ] , [ "que tal", "herib" ] } ) ----> char ****cuarteto

	cuarteto[0] ---> char ***triple_cero
		{ ["hola", "ana"], ["que tal", "herib"] } 
	cuarteto[0][0] ---> char **doble_cero_del_triple_cero
		["hola", "ana"]
	cuarteto[0][0][0] ---> char *puntero_cero_del_doble_cero_del_triple_cero
		"hola"
	cuarteto[0][0][0][0] ---> char ---> 'h'
		'h'


	*/
