#include "../../inc/push_swap.h"

void	ft_assign_position(t_stack_node **stack)
{
	int				position_assigned;
	t_stack_node	*node;

	position_assigned = 0;
	node = *stack;
	if (!(*stack) || !(node))
		return ;
	while (node != NULL)
	{
		node->position = position_assigned;
		position_assigned++;
		node = node->next;
	}
}

// Used to adjust stack_a after all elements have been pushed back in, sorted
int	ft_smallest_index_pos(t_stack_node **stack)
{
	t_stack_node	*current;
	int				smallest_index;
	int				smallest_position;

	if (!stack || !*stack)
		return (1);
	current = *stack;
	smallest_index = INT_MAX;
	ft_assign_position(stack);
	smallest_position = current->position;
	while (current != NULL)
	{
		if (current->index < smallest_index)
		{
			smallest_index = current->index;
			smallest_position = current->position;
		}
		current = current->next;
	}
	return (smallest_position);
}
