#include "push_swap.h"

void	print_el(void *content)
{
	printf("%d ", *(int *)content);
}

void	print_stack(t_list *stack)
{
	ft_lstiter(stack, print_el);
	printf("\n");
}
