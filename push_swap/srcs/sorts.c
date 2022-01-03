#include "push_swap.h"

int	chunk_sort(t_var *var)
{
	if (var->a_chunk_size)
	{
		if (!mid_point_a_to_b(var))
			return (0);
		chunk_sort(var);
	}
	else if (var->b_chunks_sizes)
	{
		if (!handle_first_b_chunk(var))
			return (0);
		chunk_sort(var);
	}
	return (1);
}

void	sort_3(t_var *var)
{
	if (is_max(var->a, var->a))
		rotate_a(var);
	else if (is_max(var->a, var->a->next))
		reverse_rotate_a(var);
	if (*(int *)var->a->content > *(int *)var->a->next->content)
		swap_a(var);
}
