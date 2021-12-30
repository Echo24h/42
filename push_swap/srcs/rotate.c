#include "push_swap.h"

void	rotate_a(t_var *var)
{
	t_list	*tmp;

	ft_putstr("ra\n");
	if (!var->a || !var->a->next)
		return ;
	tmp = var->a;
	var->a = var->a->next;
	tmp->next = NULL;
	ft_lstadd_back(&var->a, tmp);
}

void	rotate_b(t_var *var)
{
	t_list	*tmp;

	ft_putstr("rb\n");
	if (!var->b || !var->b->next)
		return ;
	tmp = var->b;
	var->b = var->b->next;
	tmp->next = NULL;
	ft_lstadd_back(&var->b, tmp);
}

void	rotate_ab(t_var *var)
{
	t_list	*tmp;

	ft_putstr("rr\n");
	if (var->a && var->a->next)
	{
		tmp = var->a;
		var->a = var->a->next;
		tmp->next = NULL;
		ft_lstadd_back(&var->a, tmp);
	}
	if (var->b && var->b->next)
	{
		tmp = var->b;
		var->b = var->b->next;
		tmp->next = NULL;
		ft_lstadd_back(&var->b, tmp);
	}
}
