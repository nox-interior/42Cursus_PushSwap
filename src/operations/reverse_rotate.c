#include "../../inc/push_swap.h"

void	ft_rev_rotate(t_stack_node **headNodePtr)
{
	t_stack_node *node_to_rotate;

	if (*headNodePtr == NULL || (*headNodePtr)->next == NULL)
		return ;
	node_to_rotate = *headNodePtr;
	while (node_to_rotate->next != NULL)
		node_to_rotate = node_to_rotate->next;
	node_to_rotate->prev->next = NULL;
	node_to_rotate->prev = NULL;
	node_to_rotate->next = *headNodePtr; 
	(*headNodePtr)->prev = node_to_rotate;
	*headNodePtr = node_to_rotate;
}

void	ft_rra(t_stack_node **stack_node)
{
	ft_rev_rotate(stack_node);
	ft_printf("rra\n");
}

void	ft_rrb(t_stack_node **stack_node)
{
	ft_rev_rotate(stack_node);
	ft_printf("rrb\n");
}

void	ft_rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	ft_printf("rrr\n");
}
