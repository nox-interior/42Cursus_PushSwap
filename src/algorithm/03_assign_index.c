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
	t_stack_node	*copy_s;
	int				index_assigned;
	int				min;
	int				max;
	int				i;

	if (!stack_node || !*stack_node)
		return ;
	ft_find_min_max(stack_node, &min, &max);
	index_assigned = 1;
	i = min;
	while (i <= max)
	{
		copy_s = *stack_node;
		while (copy_s != NULL)
		{
			if (copy_s->value == i)
			{
				copy_s->index = index_assigned++;
				break ;
			}
			copy_s = copy_s->next;
		}
		i++;
	}
}
