#include "../../inc/push_swap.h"

// Finding target nodes
static void	ft_find_next_highest_index(t_stack_node **stack_a, int index_b,
									int *target_index, int *target_pos)
{
	t_stack_node	*current_node;

	if (!stack_a || !*stack_a)
		return ;
	current_node = *stack_a;
	while (current_node != NULL)
	{
		if (current_node->index > index_b && current_node->index < *target_index)
		{
			*target_index = current_node->index;
			*target_pos = current_node->position;
		}
		current_node = current_node->next;
	}
}

static void	ft_find_lowest_index(t_stack_node **stack_a, int *target_index,
									int *target_pos)
{
	t_stack_node	*lowest_idx_in_a;

	lowest_idx_in_a = *stack_a;
	while (lowest_idx_in_a)
	{
		if (lowest_idx_in_a->index < *target_index)
		{
			*target_index = lowest_idx_in_a->index;
			*target_pos = lowest_idx_in_a->position;
		}
		lowest_idx_in_a = lowest_idx_in_a->next;
	}
}

int	ft_find_target(t_stack_node **stack_a, int index_b)
{
	int				target_index;
	int				target_pos;

	target_index = INT_MAX;
	target_pos = -1;
	if (!*stack_a || !stack_a)
		return (-1);
	ft_find_next_highest_index(stack_a, index_b, &target_index, &target_pos);
	if (target_index != INT_MAX)
		return (target_pos);
	ft_find_lowest_index(stack_a, &target_index, &target_pos);
	return (target_pos);
}
