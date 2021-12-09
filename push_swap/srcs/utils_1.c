#include "push_swap.h"

void	move_to_top_a(t_list **a, t_list *el)
{
	int	n;
	int	index;

	n = ft_lstsize(*a);
	index = get_index(*a, el);
	if (index < n / 2)
		while (index--)
			rotate_a(a);
	else
		while (index++ < n)
			reverse_rotate_a(a);
}

void	move_to_top_b(t_list **b, t_list *el)
{
	int	n;
	int	index;

	n = ft_lstsize(*b);
	index = get_index(*b, el);
	if (index < n / 2)
		while (index--)
			rotate_b(b);
	else
		while (index++ < n)
			reverse_rotate_b(b);
}

t_list	*get_next_min(t_list *lst, t_list *prev_min)
{
	t_list	*next_min;

	next_min = NULL;
	while (lst)
	{
		if (is_bigger(lst, prev_min) && is_smaller(lst, next_min))
			next_min = lst;
		lst = lst->next;
	}
	return (next_min);
}
