#include "push_swap.h"

static void	first_push_from_a_to_b(t_var *var, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (*(int *)var->a->content < var->median)
		{
			push_b(var);
			i++;
		}
		else if (*(int *)ft_lstlast(var->a)->content < var->median)
		{
			reverse_rotate_a(var);
			push_b(var);
			i++;
		}
		else
			rotate_a(var);
	}
}

static void	push_from_a_to_b(t_var *var, int n)
{
	int	count_ra;
	int	i;

	count_ra = 0;
	i = 0;
	while (i < n)
	{
		if (*(int *)var->a->content < var->median)
		{
			push_b(var);
			i++;
		}
		else
		{
			rotate_a(var);
			count_ra++;
		}
	}
	while (count_ra--)
		reverse_rotate_a(var);
}

int	mid_point_a_to_b(t_var *var)
{
	static int	first_push = 1;
	t_list		*new_chunk_size;

	while (var->a_chunk_size > 2)
	{
		if (chunk_is_in_ascending_order(var->a, var->a_chunk_size))
			break ;
		if (!get_median(var->a, var->a_chunk_size, &var->median, A_TO_B))
			return (0);
		new_chunk_size = ft_lstcreate(var->a_chunk_size / 2);
		if (!new_chunk_size)
			return (0);
		ft_lstadd_front(&var->b_chunks_sizes, new_chunk_size);
		if (first_push)
			first_push_from_a_to_b(var, var->a_chunk_size / 2);
		else
			push_from_a_to_b(var, var->a_chunk_size / 2);
		var->a_chunk_size = var->a_chunk_size / 2 + var->a_chunk_size % 2;
	}
	if (var->a_chunk_size == 2
		&& *(int *)var->a->content > *(int *)var->a->next->content)
		swap_a(var);
	first_push = 0;
	var->a_chunk_size = 0;
	return (1);
}
