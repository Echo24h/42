#include "push_swap.h"

t_list	*copy_lst(t_list *lst)
{
	t_list	*lst_copy;
	t_list	*el;

	lst_copy = NULL;
	while (lst)
	{
		el = ft_lstnew(lst->content);
		if (!el)
			return (NULL);
		ft_lstadd_back(&lst_copy, el);
		lst = lst->next;
	}
	return (lst_copy);
}