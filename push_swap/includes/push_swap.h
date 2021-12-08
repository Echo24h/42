#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define LEN_INT_MAX 10

#include "libft.h"
#include <limits.h>

int	parse(int ac, char **av, t_list **a);

// operations
void	swap_a(t_list **a);
void	swap_b(t_list **b);
void	swap_ab(t_list **a, t_list **b);
void	push_a(t_list **a, t_list **b);
void	push_b(t_list **a, t_list **b);
void	rotate_a(t_list **a);
void	rotate_b(t_list **b);
void	rotate_ab(t_list **a, t_list **b);
void	reverse_rotate_a(t_list **a);
void	reverse_rotate_b(t_list **b);
void	reverse_rotate_ab(t_list **a, t_list **b);

// dev
void	print_stack(t_list *stack);
void	print_stacks(t_list *a, t_list *b);

// utils
t_list	*copy_lst(t_list *lst);

#endif