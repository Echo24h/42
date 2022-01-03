#include "push_swap.h"

void	swap_a(t_var *var)
{
	t_list *tmp;

	ft_putstr("sa\n");
	if (!var->a || !var->a->next)
		return;
	tmp = var->a;
	var->a = var->a->next;
	tmp->next = var->a->next;
	var->a->next = tmp;
}

void	swap_b(t_var *var)
{
	t_list *tmp;

	ft_putstr("sb\n");
	if (!var->b || !var->b->next)
		return;
	tmp = var->b;
	var->b = var->b->next;
	tmp->next = var->b->next;
	var->b->next = tmp;
}

void	swap_ab(t_var *var)
{
	t_list *tmp;

	ft_putstr("ss\n");
	if (var->a && var->a->next)
	{
		tmp = var->a;
		var->a = var->a->next;
		tmp->next = var->a->next;
		var->a->next = tmp;
	}
	if (var->b && var->b->next)
	{
		tmp = var->b;
		var->b = var->b->next;
		tmp->next = var->b->next;
		var->b->next = tmp;
	}
}
