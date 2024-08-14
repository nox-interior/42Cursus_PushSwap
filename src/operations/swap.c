#include "../../inc/push_swap.h"

void	ft_swap(t_stack_node **headNodePtr)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (*headNodePtr == NULL || (*headNodePtr)->next == NULL)
		return ;
	first_node = *headNodePtr;
	second_node = first_node->next;
	first_node->next = second_node->next;
	second_node->next = first_node;
	if (first_node->next != NULL)
		first_node->next->prev = first_node;
	first_node->prev = second_node;
	*headNodePtr = second_node;
}

void	ft_sa(t_stack_node **stack_node)
{
	ft_swap(stack_node);
	ft_printf("sa\n");
}

void	ft_sb(t_stack_node **stack_node)
{
	ft_swap(stack_node);
	ft_printf("sb\n");
}
