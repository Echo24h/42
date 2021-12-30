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

void	swap_int(int *x, int *y)
{
	int	tmp;

	if (!x || !y)
		return ;
	tmp = *x;
	*x = *y;
	*y = tmp;
}

void	ft_lstdel_first(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	*lst = (*lst)->next;
	ft_lstdelone(tmp, &free);
}

t_list	*ft_lstcreate(int x)
{
	int	*n;

	n = malloc(sizeof(int) * 1);
	if (!n)
		return (NULL);
	*n = x;
	return (ft_lstnew(n));
}
