#include "push_swap.h"

void	reverse_rotate_a(t_var *var)
{
	t_list	*tmp;

	ft_putstr("rra\n");
	if (!var->a || !var->a->next)
		return ;
	tmp = var->a;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(&var->a, tmp->next);
	tmp->next = NULL;
}

void	reverse_rotate_b(t_var *var)
{
	t_list	*tmp;

	ft_putstr("rrb\n");
	if (!var->b || !var->b->next)
		return ;
	tmp = var->b;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstadd_front(&var->b, tmp->next);
	tmp->next = NULL;
}

void	reverse_rotate_ab(t_var *var)
{
	t_list	*tmp;

	ft_putstr("rrr\n");
	if (var->a && var->a->next)
	{
		tmp = var->a;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(&var->a, tmp->next);
		tmp->next = NULL;
	}
	if (var->b && var->b->next)
	{
		tmp = var->b;
		while (tmp->next->next)
			tmp = tmp->next;
		ft_lstadd_front(&var->b, tmp->next);
		tmp->next = NULL;
	}
}
