#include "../../inc/push_swap.h"

// Finding target nodes
static void	ft_find_next_highest_index(t_stack_node **stack_a, int index_b,
									int *target_index, int *target_pos)
{
	t_stack_node	*next_hi_a;

	if (!stack_a || !*stack_a)
		return ;
	next_hi_a = *stack_a;
	while (next_hi_a != NULL)
	{
		if (next_hi_a->index > index_b && next_hi_a->index < *target_index)
		{
			*target_index = next_hi_a->index;
			*target_pos = next_hi_a->position;
		}
		next_hi_a = next_hi_a->next;
	}
}

static void	ft_find_lowest_index(t_stack_node **stack_a, int *target_index,
									int *target_pos)
{
	t_stack_node	*lowest_in_a;

	lowest_in_a = *stack_a;
	while (lowest_in_a)
	{
		if (lowest_in_a->index < *target_index)
		{
			*target_index = lowest_in_a->index;
			*target_pos = lowest_in_a->position;
		}
		lowest_in_a = lowest_in_a->next;
	}
}

int	ft_find_target(t_stack_node **stack_a, int index_b)
{
	int				target_index;
	int				target_pos;
	t_stack_node	*temp_a;

	target_index = INT_MAX;
	target_pos = -1;
	if (!*stack_a || !stack_a)
		return (-1);
	temp_a = *stack_a;
	while (temp_a)
		temp_a = temp_a->next;
	ft_find_next_highest_index(stack_a, index_b, &target_index, &target_pos);
	if (target_index != INT_MAX)
		return (target_pos);
	ft_find_lowest_index(stack_a, &target_index, &target_pos);
	return (target_pos);
}
