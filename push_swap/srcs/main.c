#include "push_swap.h"

int	on_error() // need to track malloc boy
{
	ft_putstr("Error\n");
	return (0);
}

int	get_index(t_list *lst, t_list *el)
{
	int	index;

	index = 0;
	while (lst)
	{
		if (lst->content == el->content)
			return (index);
		index++;
		lst = lst->next;
	}
	return (-1);
}

t_list	*get_max(t_list *lst)
{
	t_list	*el_max;

	if (!lst)
		return (NULL);
	el_max = lst;
	lst = lst->next;
	while (lst)
	{
		if (*(int *)lst->content > *(int *)el_max->content)
			el_max = lst;
		lst = lst->next;
	}
	return (el_max);
}

t_list	*get_min(t_list *lst)
{
	t_list	*el_min;

	if (!lst)
		return (NULL);
	el_min = lst;
	lst = lst->next;
	while (lst)
	{
		if (*(int *)lst->content < *(int *)el_min->content)
			el_min = lst;
		lst = lst->next;
	}
	return (el_min);
}

void	move_to_top_a(t_list **a, t_list *el)
{
	int	n;
	int	index;

	n = ft_lstsize(*a);
	index = get_index(*a, el);
	if (index < n / 2)
		while (index--)
			rotate_a(a);
	else
		while (index++ < n)
			reverse_rotate_a(a);
}

void	move_to_top_b(t_list **b, t_list *el)
{
	int	n;
	int	index;

	n = ft_lstsize(*b);
	index = get_index(*b, el);
	if (index < n / 2)
		while (index--)
			rotate_b(b);
	else
		while (index++ < n)
			reverse_rotate_b(b);
}

void	sorting(t_list **a, t_list **b)
{
	t_list	el;

	while (*a)
	{
		move_to_top_a(a, get_min(*a));
		push_b(a, b);
	}
	while (*b)
		push_a(a, b);
}

/*
t_list	*init_chunks(int n, t_list *lst)
{
	int		size;
	int		i;
	int		j;
	t_list	*chunks;

	size = ft_lstsize(lst);
	chunks = malloc(sizeof(t_list) * n);
	if (!chunks)
		return (NULL);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j++ < size / n)
			ft_lstadd_front(&chunks[i], get_min(lst));
		i++;
	}
	while (j++ < size)
		ft_lstadd_front(&chunks[i], get_min(lst));
	return (chunks);
}
*/

int	main(int ac, char **av)
{
	int		size;
	t_list	*a;
	t_list	*b;
	int		**chunks;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!parse(ac, av, &a))
		return (on_error());
	b = copy_lst(a);
	print_stacks(a, b);
	return (0);
}