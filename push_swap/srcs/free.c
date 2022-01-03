#include "push_swap.h"

static void	free_var(t_var *var)
{
	ft_lstclear(&var->a, &free);
	ft_lstclear(&var->b, &free);
	ft_lstclear(&var->b_chunks_sizes, &free);
	free(var);
}

void	free_and_exit(t_var *var, int exit_code)
{
	free_var(var);
	exit(exit_code);
}

int	free_and_return(t_var *var, int return_val)
{
	free_var(var);
	return (return_val);
}

int	free_strs(char **strs, int x)
{
	int	i;

	i = 0;
	if (!strs)
		return (x);
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (x);
}
