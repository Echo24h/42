#include "push_swap.h"

int	chunk_is_in_ascending_order(t_list *lst, int chunk_size)
{
	t_list	*prev;
	int		i;

	if (!lst)
		return (1);
	prev = lst;
	lst = lst->next;
	i = 1;
	while (lst && i < chunk_size)
	{
		if (*(int *)lst->content < *(int *)prev->content)
			return (0);
		prev = lst;
		lst = lst->next;
		i++;
	}
	return (1);
}

int	chunk_is_in_descending_order(t_list *lst, int chunk_size)
{
	t_list	*prev;
	int		i;

	if (!lst)
		return (1);
	prev = lst;
	lst = lst->next;
	i = 1;
	while (lst && i < chunk_size)
	{
		if (*(int *)lst->content > *(int *)prev->content)
			return (0);
		prev = lst;
		lst = lst->next;
		i++;
	}
	return (1);
}
