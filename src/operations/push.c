#include "../../inc/push_swap.h"

void	ft_push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	*src = node_to_push->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->next = *dest;
	if (*dest)
		(*dest)->prev = node_to_push;
	*dest = node_to_push;
}

void	ft_pa(t_stack_node **stack_dest, t_stack_node **stack_src)
{
	ft_push(stack_dest, stack_src);
	ft_printf("pa\n");
}

void	ft_pb(t_stack_node **stack_dest, t_stack_node **stack_src)
{
	ft_push(stack_dest, stack_src);
	ft_printf("pb\n");
}
