#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	temp;		// almacena los datos de los nodos
	t_list *start = lst;	// almacena el inicio de la lista

	while (lst->next)	// mientras haya nodos para comparar (el siguiente no sea nulo)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)	// si los datos no estan en orden
		{
			temp = lst->data;		// guarda temporalmente el valor del nodo actual
			lst->data = lst->next->data;	// coloca el valor del siguiente nodo en el nodo actual
			lst->next->data = temp;		// coloca el valor temporal en el siguiente nodo
			lst = start;			// vuelve al inicio de la lista para continuar ordenando
		}
		else
			lst = lst->next;		// si los datos estan en orden, pasa al siguiente nodo
	}
	return (start);					// devuelve el inicio de la lista
}

/*
--------------------------------------------------------------------------------
Escribe la siguiente funcion:

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))

Esta función debe ordenar la lista dada como parámetro, utilizando el puntero
cmp de la función para seleccionar el orden a aplicar, y devuelve un puntero al 
primer elemento de la lista ordenada.

Los duplicados deben permanecer.

Las entradas serán siempre coherentes.

Debe utilizar el tipo t_list descrito en el archivo list.h 
que se le proporciona. Debe incluir ese fichero 
(#include "list.h"), pero no debe entregarlo. Utilizaremos nuestro propio 
para compilar su tarea.

Las funciones pasadas como cmp siempre devolverán un valor diferente de 
0 si a y b están en el orden correcto, 0 en caso contrario.

Por ejemplo, la siguiente función usada como cmp ordenará la lista 
en orden ascendente:

int ascending(int a, int b)
{
	return (a <= b);
}
--------------------------------------------------------------------------------
*/
