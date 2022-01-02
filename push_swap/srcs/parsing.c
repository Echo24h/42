#include "push_swap.h"

static int	*get_int(char *s)
{
	long int	x;
	int			*res;

	if (!is_number(s))
		return (NULL);
	if (ft_strlen(s) > LEN_INT_MAX + 1)
		return (NULL);
	x = ft_atoi_long_long(s);
	if (x < INT_MIN || x > INT_MAX)
		return (NULL);
	res = malloc(sizeof(int) * 1);
	if (!res)
		return (NULL);
	*res = (int)x;
	return (res);
}

static int	check_duplicate(t_list *lst)
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			if (*(int *)lst->content == *(int *)tmp->content)
				return (0);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
	return (1);
}

static int	parse_one_param(char *param, t_list **a)
{
	int		*val;
	int		i;
	char	**entries;
	t_list	*el;

	entries = ft_split(param, ' ');
	if (!entries || !entries[0])
		return (free_strs(entries, 0));
	i = 0;
	while (entries[i])
	{
		val = get_int(entries[i]);
		if (!val)
			return (free_strs(entries, 0));
		el = ft_lstnew(val);
		if (!el)
		{
			free(val);
			return (free_strs(entries, 0));
		}
		ft_lstadd_back(a, el);
		i++;
	}
	return(free_strs(entries, 1));
}

static int	parse_multiple_params(int ac, char **av, t_list **a)
{
	int		i;
	int		*val;
	t_list	*el;

	i = 1;
	while (i < ac)
	{
		val = get_int(av[i]);
		if (!val)
			return (0);
		el = ft_lstnew(val);
		if (!el)
		{
			free(val);
			return (0);
		}
		ft_lstadd_back(a, el);
		i++;
	}
	return (1);
}

int	parse(int ac, char **av, t_var *var)
{
	if (ac == 2 && !parse_one_param(av[1], &var->a))
		return (0);
	else if (ac > 2 && !parse_multiple_params(ac, av, &var->a))
		return (0);
	if (!check_duplicate(var->a))
		return (0);
	return (1);
}
