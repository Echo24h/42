#include "push_swap.h"

void	push_a(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_putstr("pa\n");
	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	ft_lstadd_front(a, tmp);
}

void	push_b(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_putstr("pb\n");
	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	ft_lstadd_front(b, tmp);
}