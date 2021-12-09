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
t_list	*get_min(t_list *lst);
t_list	*get_max(t_list *lst);
int		get_index(t_list *lst, t_list *el);
void	move_to_top_a(t_list **a, t_list *el);
void	move_to_top_b(t_list **b, t_list *el);
int		is_smaller(t_list *el1, t_list *el2);
int		is_equal(t_list *el1, t_list *el2);
t_list	*get_next_min(t_list *lst, t_list *prev_min);
int		is_bigger(t_list *el1, t_list *el2);
void	print_chunks_limits(int *chunks_limits, int n);
t_list	*get_el(t_list *lst, int index);

// sorts
void	selection_sort_a(t_list **a, t_list **b);
void	selection_sort_b(t_list **a, t_list **b);
void	fusion_sort(t_list **a, t_list **b);
void	chunk_sort(t_list **a, t_list **b);

#endif