#include "push_swap.h"

void	selection_sort_a(t_list **a, t_list **b)
{
	int	n;
	
	n = 0;
	while (*a)
	{
		move_to_top_a(a, get_min(*a));
		push_b(a, b);
		n++;
	}
	while (n--)
		push_a(a, b);
}

void	selection_sort_b(t_list **a, t_list **b)
{
	int	n;
	
	n = 0;
	while (*b)
	{
		move_to_top_b(b, get_min(*b));
		push_a(a, b);
		n++;
	}
	while (n--)
		push_b(a, b);
}

void	fusion_sort(t_list **a, t_list **b)
{
	int	i;
	int	n;
	t_list	*sentinel_a;
	t_list	*sentinel_b;
	
	n = ft_lstsize(*a) / 2;
	i = 0;
	while (i++ < n)
		push_b(a, b);
	selection_sort_a(a, b);
	selection_sort_b(a, b);
	sentinel_a = ft_lstnew(ft_lstlast(*a)->content);
	sentinel_b = ft_lstnew(ft_lstlast(*b)->content);
	while (sentinel_a || sentinel_b)
	{
		if (sentinel_a && is_smaller(*a, *b))
		{
			if (*(int *)(*a)->content == *(int *)sentinel_a->content)
			{
				free(sentinel_a);
				sentinel_a = NULL;
			}
			rotate_a(a);
		}
		else if (sentinel_b)
		{
			if (*(int *)(*b)->content == *(int *)sentinel_b->content)
			{
				free(sentinel_b);
				sentinel_b = NULL;
			}
			push_a(a, b);
			rotate_a(a);
		}
	}
}

// ------------------------------------------------

int	*init_chunks_limits(t_list *lst, int n)
{
	int		*chunks_limits;
	int		n_per_chunk;
	int		i;
	int		j;
	t_list	*tmp;

	n_per_chunk = ft_lstsize(lst) / n;
	chunks_limits = malloc(sizeof(int) * (n));
	if (!chunks_limits)
		return (NULL);
	tmp = NULL;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j++ < n_per_chunk)
			tmp = get_next_min(lst, tmp);
		if (i == n - 1)
		{
			j = ft_lstsize(lst) % n;
			while (j--)
				tmp = get_next_min(lst, tmp);
		}
		chunks_limits[i] = *(int *)tmp->content;
		i++;
	}
	return (chunks_limits);
}

t_list	*get_nearest_el_in_chunk(t_list *lst, int chunk_limit)
{
	t_list	*tmp;
	int	index_higher;
	int	index_lower;

	tmp = lst;
	index_higher = -1;
	index_lower = -1;
	while (tmp && *(int *)tmp->content > chunk_limit)
		tmp = tmp->next;
	index_higher = get_index(lst, tmp);
	if (tmp)
		tmp = tmp->next;
	while (tmp)
	{
		if (*(int *)tmp->content <= chunk_limit)
			index_lower = get_index(lst, tmp);
		tmp = tmp->next;
	}
	if (index_higher <= ft_lstsize(lst) - index_lower - 1)
		return (get_el(lst, index_higher));
	return (get_el(lst, index_lower));
}

void	chunk_sort(t_list **a, t_list **b)
{
	int	i;
	int	n;
	int	*chunks_limits;
	t_list	*tmp;

	// print_stacks(*a, *b);
	n = 12;
	chunks_limits = init_chunks_limits(*a, n);
	if (!chunks_limits)
		return ; // error malloc
	i = 0;
	while (i < n - 1)
	{
		tmp = get_nearest_el_in_chunk(*a, chunks_limits[i]);
		while (tmp)
		{
			move_to_top_a(a, tmp);
			push_b(a, b);
			tmp = get_nearest_el_in_chunk(*a, chunks_limits[i]);
		}
		i++;
	}
	while (*a)
	{
		move_to_top_a(a, get_min(*a));
		push_b(a, b);
	}
	while (n - 1 > 0)
	{
		tmp = get_max(*b);
		while (*(int *)tmp->content > chunks_limits[n - 1])
		{
			move_to_top_b(b, tmp);
			push_a(a, b);
			tmp = get_max(*b);
		}
		n--;
	}
	while (*b)
	{
		tmp = get_max(*b);
		move_to_top_b(b, tmp);
		push_a(a, b);
	}
	//print_chunks_limits(chunks_limits, 4);
	//print_stacks(*a, *b);
	//printf("%d\n", *(int *)get_nearest_el_in_chunk(*a, chunks_limits[0])->content);
}

// ------------------------------------------------