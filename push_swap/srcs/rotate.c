#include "push_swap.h"

void	rotate_a(t_list **a)
{
	t_list	*tmp;

	ft_putstr("ra\n");
	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = NULL;
	ft_lstadd_back(a, tmp);
}

void	rotate_b(t_list **b)
{
	t_list	*tmp;

	ft_putstr("rb\n");
	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	ft_lstadd_back(b, tmp);
}

void	rotate_ab(t_list **a, t_list **b)
{
	t_list	*tmp;

	ft_putstr("rr\n");
	if (*a && (*a)->next)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		ft_lstadd_back(a, tmp);
	}
	if (*b || (*b)->next)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		ft_lstadd_back(b, tmp);
	}
}