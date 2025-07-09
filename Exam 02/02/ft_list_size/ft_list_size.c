#include "ft_list.h"

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

//begin_list = begin_list->next;
//para acceder al siguiente nodo,
//begin_list = begin_list->data;
//para acceder al dato del nodo actual
//begin_list = begin_list->next->data;
//para acceder al siguiente nodo y al dato dentro del siguiente nodo
