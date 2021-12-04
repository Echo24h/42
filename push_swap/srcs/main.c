#include "push_swap.h"

int	on_error()
{
	ft_putstr("Error\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (!parse(ac, av, &a))
		return (on_error());
	print_stack(a);
	return (0);
}