#include "libmy.h"

void	my_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = my_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
	return ;
}
