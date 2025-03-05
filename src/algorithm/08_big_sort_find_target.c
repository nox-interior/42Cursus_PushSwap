#include "../../inc/push_swap.h"

// Finding target nodes
static void	ft_find_next_highest_index(t_stack_node **stack_a, int index_b,
									int *min_above_b, int *found_target_pos)
{
	t_stack_node	*current_node;

	if (!stack_a || !*stack_a)
		return ;
	current_node = *stack_a;
	while (current_node != NULL)
	{
		if (current_node->index > index_b && current_node->index < *min_above_b)
		{
			*min_above_b = current_node->index;
			*found_target_pos = current_node->position;
		}
		current_node = current_node->next;
	}
}

static void	ft_find_lowest_index(t_stack_node **stack_a, int *min_index_a,
									int *found_target_pos)
{
	t_stack_node	*current_node;

	current_node = *stack_a;
	while (current_node)
	{
		if (current_node->index < *min_index_a)
		{
			*min_index_a = current_node->index;
			*found_target_pos = current_node->position;
		}
		current_node = current_node->next;
	}
}

int	ft_find_target(t_stack_node **stack_a, int index_b)
{
	int				min_above_b;
	int				found_target_pos;

	min_above_b = INT_MAX;
	found_target_pos = -1;
	if (!*stack_a || !stack_a)
		return (-1);
	ft_find_next_highest_index(stack_a, index_b, &min_above_b,
		&found_target_pos);
	if (min_above_b != INT_MAX)
		return (found_target_pos);
	else
	{
		ft_find_lowest_index(stack_a, &min_above_b, &found_target_pos);
		return (found_target_pos);
	}
}
