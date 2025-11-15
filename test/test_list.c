#include "../libmy.h"
#include <stdio.h>
#include <stdlib.h>

void	print_title(const char *title)
{
	printf("\n===== %s =====\n", title);
}

// Print list contents (for testing)
void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content);
		lst = lst->next;
	}
	printf("NULL\n");
}

void	print_content(void *content)
{
	char	*str;

	str = (char *)content;
	printf("Printing content: %s\n", str);
}

// Example of the function to be mapped over the list. MUST RETURN VOID POINTER
void	*to_upper(void *content)
{
	char	*str;

	str = (char *)content;
	char *new_str = my_strdup(str); // Copy the string
	if (new_str)
	{
		for (int i = 0; new_str[i]; i++)
			new_str[i] = my_toupper((unsigned char)new_str[i]);
	}
	return ((void *)new_str);
}

int	main(void)
{
	t_list	*list;
	t_list	*node;
	t_list	*last;
	t_list	*upper_list;
	t_list	*tmp;

	list = NULL;
	print_title("my_lstnew / my_lstadd_front / my_lstadd_back");
	// NOTE: my_strdup is used to turn the stack-allocated string "1" into a
	// heap-allocated string, which can can be cleared with 'free'.
	node = my_lstnew(my_strdup("one"));
	my_lstadd_front(&list, node);
	node = my_lstnew(my_strdup("zero"));
	my_lstadd_front(&list, node);
	node = my_lstnew(my_strdup("two"));
	my_lstadd_back(&list, node);
	node = my_lstnew(my_strdup("minus one"));
	my_lstadd_front(&list, node);
	node = my_lstnew(my_strdup("three"));
	my_lstadd_back(&list, node);
	print_list(list);
	print_title("my_lstsize / my_lstlast");
	printf("size: %d\n", my_lstsize(lis));
	last = my_lstlast(list);
	printf("last content: %s\n", (char *)last->content);
	print_title("my_lstdelone / my_lstclear");
	tmp = list->next;
	list->next = list->next->next;
		// Need to get the next-next node *before* deleting the next node
	my_lstdelone(tmp, free);
	printf("amyer delone, list: ");
	print_list(list);
	my_lstclear(&list, free);
	printf("amyer clear, list: %p\n", (void *)list);
	print_title("my_lstiter / my_lstmap");
	my_lstadd_back(&list, my_lstnew(my_strdup("abc")));
	my_lstadd_back(&list, my_lstnew(my_strdup("def")));
	my_lstadd_back(&list, my_lstnew(my_strdup("ghi")));
	printf("original:\n");
	print_list(list);
	printf("my_lstiter -> print content:\n");
	my_lstiter(list, print_content);
	printf("my_lstmap -> uppercase copy:\n");
	upper_list = my_lstmap(list, to_upper, free);
	printf("Uppercase copy:\t");
	print_list(upper_list);
	printf("Original:\t");
	print_list(list);
	my_lstclear(&list, free);
	my_lstclear(&upper_list, free);
	return (0);
}
