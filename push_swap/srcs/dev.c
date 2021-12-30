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

void	print_stacks(t_list *a, t_list *b)
{
	printf("a : ");
	print_stack(a);
	printf("b : ");
	print_stack(b);
}

void	print_chunks_limits(int *chunks_limits, int n)
{
	int	i;

	i = 0;
	printf("chunks_limits: ");
	while (i < n)
		printf("%d ", chunks_limits[i++]);
	printf("\n");
}

void	print_var(t_var *var)
{
	if (!var)
		return ;
	print_stacks(var->a, var->b);
	printf("a_chunk_size: %d\n", var->a_chunk_size);
	printf("b_chunks_sizes: ");
	print_stack(var->b_chunks_sizes);
	printf("\n");
}

void	print_array(int *array, int n)
{
	int	i;

	i = 0;
	while (i < n)
		printf("%d ", array[i++]);
	printf("\n");
}
