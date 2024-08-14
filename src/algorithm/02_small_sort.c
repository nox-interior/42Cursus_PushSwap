#include "../../inc/push_swap.h"

static int	ft_find_highest_index(t_stack_node *stack_node)
{
	int	index;

	if (!stack_node)
		return (-1);
	index = stack_node->index;
	while (stack_node)
	{
		if (stack_node->index > index)
			index = stack_node->index;
		stack_node = stack_node->next;
	}
	return (index);
}

void	ft_three_nodes_sort(t_stack_node **stack_node)
{
	int	highest_index;

	if (!(*stack_node) || !(*stack_node)->next || !(*stack_node)->next->next
		|| (*stack_node)->next->next->next != NULL)
		return ;
	highest_index = ft_find_highest_index(*stack_node);
	if ((*stack_node)->index == highest_index)
		ft_ra(stack_node);
	else if ((*stack_node)->next->index == highest_index)
		ft_rra(stack_node);
	if ((*stack_node)->index > (*stack_node)->next->index)
		ft_sa(stack_node);
}
