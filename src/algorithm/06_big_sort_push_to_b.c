#include "../../inc/push_swap.h"

/*
The condition (stack_len > 6) in the while loop is necessary because we first
measure the length of the stack, and its value remains unchanged as the
function runs. If this condition was not in place, or we'd set a lower value
to it, the while loop would be entered with stacks with less elements than 6, 
which would lead to a (stack_len / 2) that could result in pushing more
elements to stack_b than needed, ending up with less than 3 elements to be
sorted in stack_a. This, in the end, would produce unnecessary and extra
costly operations in order to bring back the elements to stack_a once sorted.
*/ 
int	ft_stack_len(t_stack_node *stack)
{
	int	length;

	length = 0;
	if (!stack)
		return (0);
	while (stack)
	{
		stack = stack->next;
		length++;
	}
	return (length);
}

static int	ft_count_below_median(t_stack_node *stack, int median)
{
	int	count;

	count = 0;
	while (stack)
	{
		if (stack->index < median)
			count++;
		stack = stack->next;
	}
	return (count);
}

void	ft_push_to_b(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	stack_len;
	int	pushed_nodes;
	int	median;

	stack_len = ft_stack_len(*stack_a);
	median = stack_len / 2;
	pushed_nodes = 0;
	while (stack_len > 6 && pushed_nodes < median)
	{
		if ((*stack_a)->index < median)
		{
			ft_pb(stack_b, stack_a);
			pushed_nodes++;
		}
		else if (ft_count_below_median(*stack_a, median))
			ft_ra(stack_a);
		else
			break ;
	}
	while (stack_len - pushed_nodes > 3)
	{
		ft_pb(stack_b, stack_a);
		pushed_nodes++;
	}
}
