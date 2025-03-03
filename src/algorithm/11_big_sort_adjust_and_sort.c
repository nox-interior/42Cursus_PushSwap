#include "../../inc/push_swap.h"

void	ft_adjust_stack(t_stack_node **stack_a)
{
	int	stack_len;
	int	min_index_pos;
	int	rotations;
	
	stack_len = ft_stack_len(*stack_a);
	min_index_pos = ft_min_index_pos(stack_a);
	if (min_index_pos <= stack_len / 2)
	{
		rotations = min_index_pos;
		while (rotations-- > 0)
			ft_ra(stack_a);
	}
	else
	{
		rotations = stack_len - min_index_pos;
		while (rotations-- > 0)
			ft_rra(stack_a);
	}
}

bool	ft_sorted_stack(t_stack_node *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	ft_big_sort(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				index_b;
	t_stack_node	*temp_b;

	ft_push_to_b(stack_a, stack_b);
	ft_three_nodes_sort(stack_a);
	while (*stack_b)
	{
		ft_assign_position(stack_a);
		ft_assign_position(stack_b);
		temp_b = *stack_b;
		while (temp_b)
		{
			index_b = temp_b->index;
			temp_b->target_pos = ft_find_target(stack_a, index_b);
			temp_b = temp_b->next;
		}
		ft_calculate_moves(stack_a, stack_b);
		ft_do_optimal_move(stack_a, stack_b);
	}
	if (!ft_sorted_stack(*stack_a))
		ft_adjust_stack(stack_a);
}
