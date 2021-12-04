#include "push_swap.h"

void	reverse_rotate_a(t_list **a)
{
	t_list	*tmp;

	ft_putstr("rra\n");
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(a, tmp->next);
	tmp->next = NULL;
}

void	reverse_rotate_b(t_list **b)
{
	t_list	*tmp;

	ft_putstr("rrb\n");
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(b, tmp->next);
	tmp->next = NULL;
}

void	reverse_rotate_ab(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_putstr("rrr\n");
	if (*a && (*a)->next)
	{
		tmp = *a;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(a, tmp->next);
		tmp->next = NULL;
	}
	if (*b || (*b)->next)
	{
		tmp = *b;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(b, tmp->next);
		tmp->next = NULL;
	}
}
