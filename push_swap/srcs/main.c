#include "push_swap.h"

int	on_error() // need to track malloc boy
{
	ft_putstr("Error\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*t1;
	t_list	*t2;
	int		size;
	t_list	*a;
	t_list	*b;
	int		**chunks;
	int		*x;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!parse(ac, av, &a))
		return (on_error());
	if (!a || ft_lstsize(a) == 1)
		return (0); // nothing to be done, check subject
	//print_stacks(a, b);
	//t1 = ft_lstnew()
	//fusion_sort(&a, &b);
	//print_stacks(a, b);
	//system("leaks push_swap");
	chunk_sort(&a, &b);
	return (0);
}
