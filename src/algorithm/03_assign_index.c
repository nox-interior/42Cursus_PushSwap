#include "../../inc/push_swap.h"

static void	ft_find_min_max(t_stack_node **stack_node, int *min, int *max)
{
	t_stack_node	*temp_s;

	if (!stack_node)
		return ;
	temp_s = *stack_node;
	*min = temp_s->value;
	*max = temp_s->value;
	while (temp_s != NULL)
	{
		if (temp_s->value < *min)
			*min = temp_s->value;
		if (temp_s->value > *max)
			*max = temp_s->value;
		temp_s = temp_s->next;
	}
}

void	ft_assign_index(t_stack_node **stack_node)
{
	t_stack_node	*current_node;
	int				index_assigned;
	int				min;
	int				max;
	int				value_to_find;

	if (!stack_node || !*stack_node)
		return ;
	ft_find_min_max(stack_node, &min, &max);
	index_assigned = 1;
	value_to_find = min;
	while (value_to_find <= max)
	{
		current_node = *stack_node;
		while (current_node != NULL)
		{
			if (current_node->value == value_to_find)
			{
				current_node->index = index_assigned++;
				break ;
			}
			current_node = current_node->next;
		}
		value_to_find++;
	}
}
