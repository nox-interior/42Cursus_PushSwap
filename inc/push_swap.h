#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/inc/libft.h"
# include "../libft/inc/ft_printf.h"

typedef struct s_stack_node
{
	int						value;
	int						index;
	int						position;
	int						target_pos;
	int						moves_a;
	int						moves_b;
	struct s_stack_node		*next;
	struct s_stack_node		*prev;
}				t_stack_node;

// operations
void	ft_swap(t_stack_node **headNodePtr);
void	ft_sa(t_stack_node **stack_node);
void	ft_sb(t_stack_node **stack_node);
void	ft_rotate(t_stack_node **headNodePtr);
void	ft_ra(t_stack_node **stack_node);
void	ft_rb(t_stack_node **stack_node);
void	ft_rr(t_stack_node **stack_a, t_stack_node **stack_b);
void	ft_rev_rotate(t_stack_node **headNodePtr);
void	ft_rra(t_stack_node **stack_node);
void	ft_rrb(t_stack_node **stack_node);
void	ft_rrr(t_stack_node **stack_a, t_stack_node **stack_b);
void	ft_push(t_stack_node **dest, t_stack_node **src);
void	ft_pa(t_stack_node **stack_dest, t_stack_node **stack_src);
void	ft_pb(t_stack_node **stack_dest, t_stack_node **stack_src);

// algorithm
void	ft_free_list(t_stack_node **headNodePtr);
void	ft_free_errors(t_stack_node **stack_a, t_stack_node **stack_b);
void	ft_three_nodes_sort(t_stack_node **stack_node);
void	ft_assign_index(t_stack_node **stack_node);
bool	ft_is_nbr(char *str);
bool	ft_check_limits(const char *str);
bool	ft_check_duplicates(t_stack_node *stack, int nbr);
t_stack_node	**ft_init_stack(t_stack_node **stack_a, int argc, char **argv);
int	ft_stack_len(t_stack_node *stack);
void	ft_push_to_b(t_stack_node **stack_a, t_stack_node **stack_b);
void	ft_assign_position(t_stack_node **stack);
int	ft_smallest_index_pos(t_stack_node **stack);
int	ft_find_target(t_stack_node **stack_a, int index_b);
void	ft_calculate_moves(t_stack_node **stack_a, t_stack_node **stack_b);
void	ft_move_node(t_stack_node **stack_a, t_stack_node **stack_b,
					int moves_a, int moves_b);
void	ft_do_optimal_move(t_stack_node **stack_a, t_stack_node **stack_b);
void	ft_adjust_stack(t_stack_node **stack_a);
int	ft_sorted_stack(t_stack_node *stack);
void	ft_big_sort(t_stack_node **stack_a, t_stack_node **stack_b);
int	main(int argc, char **argv);

#endif
