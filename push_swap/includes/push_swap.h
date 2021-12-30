#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define LEN_INT_MAX 10
# define A_TO_B	0
# define B_TO_A 1

#include "libft.h"
#include <limits.h>

typedef struct	s_var
{
	t_list	*a;
	t_list	*b;
	t_list	*b_chunks_sizes;
	int		a_chunk_size;
	int		median;
}	t_var;

int		*get_array(t_list *lst, int n);
void	quick_sort(int *array, int low, int high);
int		partition(int *array, int low, int high);

t_list	*new_chunk_size(int size);
int		parse(int ac, char **av, t_var *var);

// operations
void	swap_a(t_var *var);
void	swap_b(t_var *var);
void	swap_ab(t_var *var);
void	push_a(t_var *var);
void	push_b(t_var *var);
void	rotate_a(t_var *var);
void	rotate_b(t_var *var);
void	rotate_ab(t_var *var);
void	reverse_rotate_a(t_var *var);
void	reverse_rotate_b(t_var *var);
void	reverse_rotate_ab(t_var *var);

// dev
void	print_stack(t_list *stack);
void	print_stacks(t_list *a, t_list *b);
void	print_var(t_var *var);
void	print_array(int *array, int n);

// utils
t_list	*copy_lst(t_list *lst);
t_list	*get_min(t_list *lst);
t_list	*get_max(t_list *lst);
int		get_index(t_list *lst, t_list *el);
int		is_smaller(t_list *el1, t_list *el2);
int		is_equal(t_list *el1, t_list *el2);
t_list	*get_next_min(t_list *lst, t_list *prev_min);
int		is_bigger(t_list *el1, t_list *el2);
void	print_chunks_limits(int *chunks_limits, int n);
t_list	*get_el(t_list *lst, int index);
int		chunk_is_in_ascending_order(t_list *lst, int chunk_size);
int		chunk_is_in_descending_order(t_list *lst, int chunk_size);
void	swap_int(int *x, int *y);
void	ft_lstdel_first(t_list **lst);
t_list	*ft_lstcreate(int x);

// chunk_sort
int	mid_point_a_to_b(t_var *var);
int	handle_first_b_chunk(t_var *var);
int	chunk_sort(t_var *var);

#endif