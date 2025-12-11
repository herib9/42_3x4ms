#include "list.h"

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct	s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

#endif

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	temp;
	t_list *start;

	start = lst;
	while (lst->next)
	{
		if (((*cmp)(lst->data, lst->next->data)) == 0)
		{
			temp = lst->data;
			lst->data = lst->next->data;
			lst->next->data = temp;
			lst = start;
		}
		else
			lst = lst->next;
	}
	return (start);
}

/*Assignment name  : sort_list
Expected files   : sort_list.c
Allowed functions: 

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
--------------------------------------------------------------------------------*/
