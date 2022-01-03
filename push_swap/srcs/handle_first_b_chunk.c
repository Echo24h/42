#include "push_swap.h"

void	push_from_b_to_a(t_var *var, int n)
{
	int	count_rb;
	int	i;

	count_rb = 0;
	i = 0;
	while (i < n)
	{
		if (*(int *)var->b->content > var->median)
		{
			push_a(var);
			i++;
		}
		else if (!var->b_chunks_sizes->next && *(int *)ft_lstlast(var->b)->content > var->median)
		{
			reverse_rotate_b(var);
			push_a(var);
			i++;
		}
		else
		{
			rotate_b(var);
			count_rb++;
		}
	}
	if (var->b_chunks_sizes->next)
	{
		while (count_rb--)
			reverse_rotate_b(var);
	}
}

int	handle_first_b_chunk(t_var *var)
{
	if (chunk_is_in_descending_order(var->b, *(int *)var->b_chunks_sizes->content))
	{
		while ((*(int *)var->b_chunks_sizes->content)--)
			push_a(var);
		ft_lstdel_first(&var->b_chunks_sizes);
		return (1);
	}
	if (*(int *)var->b_chunks_sizes->content > 2)
	{
		if (!get_median(var->b, *(int *)var->b_chunks_sizes->content, &var->median, B_TO_A))
			return (0);
		var->a_chunk_size = *(int *)var->b_chunks_sizes->content / 2;
		push_from_b_to_a(var, *(int *)var->b_chunks_sizes->content / 2);
		*(int *)var->b_chunks_sizes->content = *(int *)var->b_chunks_sizes->content / 2
			+ *(int *)var->b_chunks_sizes->content % 2;
	}
	else
	{
		if (*(int *)var->b_chunks_sizes->content == 2
			&& *(int *)var->b->content < *(int *)var->b->next->content)
			swap_b(var);
		while ((*(int *)var->b_chunks_sizes->content)--)
			push_a(var);
		ft_lstdel_first(&var->b_chunks_sizes);
	}
	return (1);
}
