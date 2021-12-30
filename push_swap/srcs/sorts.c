#include "push_swap.h"

int	*get_array(t_list *lst, int n)
{
	int	*array;
	int	i;

	if (!lst)
		return (NULL);
	array = malloc(sizeof(int) * n);
	if (!array)
		return (NULL); // error 1
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
		return (0); // error 1
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

	if (!chunk_is_in_ascending_order(var->a, var->a_chunk_size))
	{
		while (var->a_chunk_size > 2)
		{
			if (!get_median(var->a, var->a_chunk_size, &var->median, A_TO_B))
				return (0); // error 1
			new_chunk_size = ft_lstcreate(var->a_chunk_size / 2);
			if (!new_chunk_size)
				return (0); // error 2
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
	}
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
		else
		{
			rotate_b(var);
			count_rb++;
		}
	}
	while (count_rb--)
		if (var->b_chunks_sizes->next)
			reverse_rotate_b(var);
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
			return (0); // error
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
			return (0); // error
		chunk_sort(var);
	}
	else if (var->b_chunks_sizes)
	{
		if (!handle_first_b_chunk(var))
			return (0); // error
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
















/*
void	first_step(t_var *var)
{
	int		i;
	int		n;
	int		median;
	t_list	*tmp;

	//printf("Enter in first_step\n");
	n = ft_lstsize(var->a);
	while (n > 2)
	{
		var->array = get_array(var->a, n); // error malloc
		quick_sort(var->array, 0, n - 1);
		median = var->array[n / 2];
		free(var->array);
		tmp = ft_lstcreate(n / 2); // error malloc
		ft_lstadd_front(&var->b_chunks_sizes, tmp);
		i = 0;
		while (i < n / 2)
		{
			if (*(int *)var->a->content < median)
			{
				push_b(var);
				i++;
			}
			else if (*(int *)ft_lstlast(var->a)->content < median)
			{
				reverse_rotate_a(var);
				push_b(var);
				i++;
			}
			else
				rotate_a(var);
		}
		n = n / 2 + n % 2;
	}
	if (*(int *)var->a->content > *(int *)var->a->next->content)
		swap_a(var);
}

void	from_a_to_b(t_var *var)
{
	int		i;
	int		j;
	int		n;
	int 	k;
	int		median;
	t_list	*tmp;

	//printf("Enter in from_a_to_b\n");
	while (var->a_chunks_sizes)
	{
		while (*(int *)var->a_chunks_sizes->content > 2)
		{
			n = *(int *)var->a_chunks_sizes->content;
			var->array = get_array(var->a, n);
			quick_sort(var->array, 0, n - 1);
			median = var->array[n / 2];
			free(var->array);
			tmp = ft_lstcreate(n / 2);
			ft_lstadd_front(&var->b_chunks_sizes, tmp);
			//printf("median: %d | n: %d\n", median, n);
			i = 0;
			j = 0;
			k = 0;
			while (i < n / 2)
			{
				
				if (k > 15)
				{
					print_var(var);
					exit(0);
				}
				if (*(int *)var->a->content < median)
				{
					push_b(var);
					i++;
				}
				else
				{
					rotate_a(var);
					j++;
				}
				k++;
			}
			while (j--)
				reverse_rotate_a(var);
			*(int *)var->a_chunks_sizes->content = n / 2 + n % 2;
		}
		if (*(int *)var->a_chunks_sizes->content == 2)
		{
			if (*(int *)var->a->content > *(int *)var->a->next->content)
				swap_a(var);
			if (var->a_chunks_sizes->next)
			{
				push_b(var);
				push_b(var);
				tmp = ft_lstcreate(2);
				ft_lstadd_front(&var->b_chunks_sizes, tmp);
			}
		}
		else if (var->a_chunks_sizes->next)
		{
			push_b(var);
			tmp = ft_lstcreate(1);
			ft_lstadd_front(&var->b_chunks_sizes, tmp);
		}
		ft_lst_remove_one(&var->a_chunks_sizes);
	}
}

void	from_b_to_a(t_var *var)
{
	int		i;
	int		j;
	int		k;
	int		z;
	int		n;
	int		median;
	t_list	*tmp;

	//printf("Enter in from_b_to_a\n");
	while (var->b_chunks_sizes)
	{
		while (*(int *)var->b_chunks_sizes->content > 2)
		{
			n = *(int *)var->b_chunks_sizes->content;
			var->array = get_array(var->b, n);
			quick_sort(var->array, 0, n - 1);
			median = var->array[n / 2];
			//while (++i < n)
			//printf("%d: %d | ", i, var->array[i]);
			//printf("\n");
			free(var->array);
			z = 1;
			if (n % 2)
				z = 0;
			tmp = ft_lstcreate(n / 2 - z);
			ft_lstadd_front(&var->a_chunks_sizes, tmp);
			//printf("median: %d | n: %d\n", median, n);
			i = 0;
			j = 0;
			k = 0;
			while (i < n / 2 - z)
			{
				
				if (k > 15)
				{
					print_var(var);
					exit(0);
				}
				
				if (*(int *)var->b->content > median)
				{
					push_a(var);
					i++;
				}
				else
				{
					//printf("before rotate: %d\n", *(int *)var->b->content);
					rotate_b(var);
					j++;
				}
				k++;
			}
			while (j--)
				reverse_rotate_b(var);
			*(int *)var->b_chunks_sizes->content = n / 2 + 1;
		}
		if (*(int *)var->b_chunks_sizes->content == 2)
		{
			if (*(int *)var->b->content < *(int *)var->b->next->content)
				swap_b(var);
			if (var->b_chunks_sizes->next)
			{
				tmp = ft_lstcreate(2);
				ft_lstadd_front(&var->a_chunks_sizes, tmp);
				push_a(var);
				push_a(var);
			}
		}
		else if (var->b_chunks_sizes->next)
		{
			tmp = ft_lstcreate(1);
			ft_lstadd_front(&var->a_chunks_sizes, tmp);
			push_a(var);
		}
		ft_lst_remove_one(&var->b_chunks_sizes);
	}
}

void	my_sort(t_var *var)
{
	if (var->a_chunks_sizes)
	{
		from_a_to_b(var);
		my_sort(var);
	}
	else if (var->b_chunks_sizes)
	{
		from_b_to_a(var);
		my_sort(var);
	}
	else
	{
		while (var->b)
			push_a(var);
	}
}
*/