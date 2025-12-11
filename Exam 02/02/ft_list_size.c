#include "ft_list.h"

#ifndef FT_LIST_H
# define FT_LIST_H

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

#endif

int	ft_list_size(t_list *begin_list)
{
	int	count = 0;

	while (begin_list)
	{
		begin_list = begin_list->next;
		count++;
	}
	return (count);
}

/*begin_list = begin_list->next;
para acceder al siguiente nodo,
begin_list = begin_list->data;
para acceder al dato del nodo actual
begin_list = begin_list->next->data;
para acceder al siguiente nodo y al dato dentro del siguiente nodo
--------------------------------------------------------------------------------
Assignment name  : ft_list_size
Expected files   : ft_list_size.c
Allowed functions: 
--------------------------------------------------------------------------------

Escribe una función que devuelva el número de elementos en la lista enlazada
que se le pasa como argumento.

Debe ser declarada de la siguiente manera:

int	ft_list_size(t_list *begin_list);

Debes utilizar la siguiente estructura y entregarla como un archivo llamado
ft_list.h:

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;
--------------------------------------------------------------------------------*/
