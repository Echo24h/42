#include "push_swap.h"

int	*get_array(t_list *lst, int n)
{
	int	*array;
	int	i;

	if (!lst)
		return (NULL);
	array = malloc(sizeof(int) * n);
	if (!array)
		return (NULL);
	i = 0;
	while (i < n && lst)
	{
		array[i++] = *(int *)lst->content;
		lst = lst->next;
	}
	return (array);
}

int	get_median(t_list *lst, int chunk_size, int *median, int direction)
{
	int	*array;

	array = get_array(lst, chunk_size);
	if (!array)
		return (0);
	quick_sort(array, 0, chunk_size - 1);
	if (direction == B_TO_A && !(chunk_size % 2))
		*median = array[(chunk_size / 2) - 1];
	else
		*median = array[chunk_size / 2];
	free(array);
	return (1);
}

void	first_push_from_a_to_b(t_var *var, int n)
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

void	push_from_a_to_b(t_var *var, int n)
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
	int			i;
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
	int	i;

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
