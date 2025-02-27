#include "../../inc/push_swap.h"

void	ft_assign_position(t_stack_node **stack)
{
	int				position_assigned;
	t_stack_node	*current_node;

	position_assigned = 0;
	current_node = *stack;
	if (!(*stack) || !(current_node))
		return ;
	while (current_node != NULL)
	{
		current_node->position = position_assigned;
		position_assigned++;
		current_node = current_node->next;
	}
}

// Used to adjust stack_a after all elements have been pushed back in, sorted
int	ft_smallest_index_pos(t_stack_node **stack)
{
	t_stack_node	*current_node;
	int				smallest_index;
	int				smallest_position;

	if (!stack || !*stack)
		return (-1);
	current_node = *stack;
	smallest_index = INT_MAX;
	ft_assign_position(stack);
	smallest_position = current_node->position;
	while (current_node != NULL)
	{
		if (current_node->index < smallest_index)
		{
			smallest_index = current_node->index;
			smallest_position = current_node->position;
		}
		current_node = current_node->next;
	}
	return (smallest_position);
}
