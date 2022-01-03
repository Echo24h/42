#include "push_swap.h"

void	push_a(t_var *var)
{
	t_list	*tmp;

	ft_putstr("pa\n");
	if (!var->b)
		return ;
	tmp = var->b;
	var->b = var->b->next;
	ft_lstadd_front(&var->a, tmp);
}

void	push_b(t_var *var)
{
	t_list	*tmp;

	ft_putstr("pb\n");
	if (!var->a)
		return ;
	tmp = var->a;
	var->a = var->a->next;
	ft_lstadd_front(&var->b, tmp);
}
