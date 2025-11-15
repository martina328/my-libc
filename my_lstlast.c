#include "libmy.h"

t_list	*my_lstlast(t_list *lst)
{
	t_list	*curr;

	if (!lst)
		return (NULL);
	curr = lst;
	while (curr != NULL && curr->next != NULL)
	{
		curr = curr->next;
	}
	return (curr);
}
