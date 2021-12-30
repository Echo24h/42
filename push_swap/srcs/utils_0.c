#include "push_swap.h"

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
