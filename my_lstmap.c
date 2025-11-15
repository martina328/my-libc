#include "libmy.h"

static t_list	*free_list(t_list *new_head, void *new_content,
		void (*del)(void *))
{
	del(new_content);
	my_lstclear(&new_head, del);
	return (NULL);
}

t_list	*my_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*curr;
	t_list	*new_head;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	curr = lst;
	new_head = NULL;
	while (curr)
	{
		new_content = f(curr->content);
		// if (!new_content)
		// 	return (free_list(new_head, new_content, del));
		new_node = my_lstnew(new_content);
		if (!new_node)
			return (free_list(new_head, new_content, del));
		my_lstadd_back(&new_head, new_node);
		curr = curr->next;
	}
	return (new_head);
}
