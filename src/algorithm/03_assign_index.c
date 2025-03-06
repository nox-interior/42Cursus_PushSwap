#include "../../inc/push_swap.h"

void	ft_assign_index(t_stack_node **stack_a)
{
	t_stack_node	*current_node;
	int				max;
	int				len;

	len = ft_stack_len(*stack_a);
	while (len >= 1)
	{
		current_node = *stack_a;
		max = INT_MIN;
		while (current_node)
		{
			if (current_node->value > max && current_node->index == -1)
				max = current_node->value;
			current_node = current_node->next;
		}
		current_node = *stack_a;
		while (current_node)
		{
			if (current_node->value == max)
				current_node->index = len--;
			current_node = current_node->next;
		}
	}
}
