#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*freeMe;

	tmp = *lst;
	while (*tmp)
	{
		(*del)(tmp->content);
		freeMe = tmp;
		tmp = tmp->next;
		free(freeMe);
	}
	*lst = NULL;
}