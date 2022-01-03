#include "push_swap.h"

int	chunk_is_in_ascending_order(t_list *lst, int chunk_size)
{
	t_list	*prev;
	int		i;

	if (!lst)
		return (1);
	prev = lst;
	lst = lst->next;
	i = 1;
	while (lst && i < chunk_size)
	{
		if (*(int *)lst->content < *(int *)prev->content)
			return (0);
		prev = lst;
		lst = lst->next;
		i++;
	}
	return (1);
}

int	chunk_is_in_descending_order(t_list *lst, int chunk_size)
{
	t_list	*prev;
	int		i;

	if (!lst)
		return (1);
	prev = lst;
	lst = lst->next;
	i = 1;
	while (lst && i < chunk_size)
	{
		if (*(int *)lst->content > *(int *)prev->content)
			return (0);
		prev = lst;
		lst = lst->next;
		i++;
	}
	return (1);
}

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
