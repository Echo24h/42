#include "push_swap.h"

int	on_error() // need to track malloc boy
{
	ft_putstr("Error\n");
	return (0);
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	if (!parse(ac, av, &a))
		return (on_error());
	print_stacks(a, b);
	swap_a(&a);
	print_stacks(a, b);
	push_b(&a, &b);
	print_stacks(a, b);
	push_b(&a, &b);
	print_stacks(a, b);
	swap_b(&b);
	print_stacks(a, b);
	push_b(&a, &b);
	print_stacks(a, b);
	rotate_ab(&a, &b);
	print_stacks(a, b);
	swap_ab(&a, &b);
	print_stacks(a, b);
	reverse_rotate_ab(&a, &b);
	print_stacks(a, b);
	return (0);
}