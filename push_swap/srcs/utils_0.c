#include "push_swap.h"

t_list	*copy_lst(t_list *lst)
{
	t_list	*lst_copy;
	t_list	*el;

	lst_copy = NULL;
	while (lst)
	{
		el = ft_lstnew(lst->content);
		if (!el)
			return (NULL);
		ft_lstadd_back(&lst_copy, el);
		lst = lst->next;
	}
	return (lst_copy);
}

int	get_index(t_list *lst, t_list *el)
{
	int	index;

	if (!el)
		return (-1);
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

t_list	*get_el(t_list *lst, int index)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (i == index)
			return (lst);
		lst = lst->next;
		i++;
	}
	return (NULL);
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

int	is_smaller(t_list *el1, t_list *el2)
{
	if (!el1)
		return (0);
	if (!el2)
		return (1);
	if (el1->content < el2->content)
		return (1);
	return (0);
}

int	is_bigger(t_list *el1, t_list *el2)
{
	if (!el1)
		return (0);
	if (!el2)
		return (1);
	if (el1->content > el2->content)
		return (1);
	return (0);
}

int	is_equal(t_list *el1, t_list *el2)
{
	if (!el1 && !el2)
		return (1);
	if (!el1 || !el2)
		return (0);
	if (*(int *)el1->content != *(int *)el2->content)
		return (0);
	return (1);
}

int	is_max(t_list *lst, t_list *el)
{
	while (lst)
	{
		if (*(int *)lst->content > *(int *)el->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
