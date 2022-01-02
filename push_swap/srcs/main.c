#include "push_swap.h"

void	free_var(t_var *var)
{
	ft_lstclear(&var->a, &free);
	ft_lstclear(&var->b, &free);
	ft_lstclear(&var->b_chunks_sizes, &free);
	free(var);
}

int	exit_and_free(t_var *var, int x)
{
	free_var(var);
	system("leaks push_swap");
	return (x);
}

int	init_var(t_var **var)
{
	*var = malloc(sizeof(t_var) * 1);
	if (!*var)
		return (0);
	(*var)->a = NULL;
	(*var)->b = NULL;
	(*var)->a_chunk_size = 0;
	(*var)->b_chunks_sizes = NULL;
	return (1);
}

int	main(int ac, char **av)
{
	t_var	*var;
	int		i;
	int		n;

	if (ac < 2 || !init_var(&var))
		return (EXIT_FAILURE);
	if (!parse(ac, av, var))
	{
		ft_putstr("Error\n");
		return (exit_and_free(var, EXIT_FAILURE)); // check leaks
	}
	if (!var->a->next)
		return (exit_and_free(var, EXIT_SUCCESS)); // need to free
	var->a_chunk_size = ft_lstsize(var->a);
	if (var->a_chunk_size == 3)
		sort_3(var);
	else if (!chunk_sort(var))
		return (exit_and_free(var, EXIT_FAILURE));
	return (exit_and_free(var, EXIT_SUCCESS));
}
