#include "push_swap.h"

void	swap_a(t_list **a)
{
	t_list	*tmp;

	ft_putstr("sa\n");
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
}

void	swap_b(t_list **b)
{
	t_list	*tmp;

	ft_putstr("sb\n");
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
}

void	swap_ab(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_putstr("ss\n");
	if (*a || (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = (*a)->next;
		(*a)->next = tmp;
	}
	if (*b || (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = (*b)->next;
		(*b)->next = tmp;
	}
}