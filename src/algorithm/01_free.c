#include "../../inc/push_swap.h"

void	ft_free_list(t_stack_node **headNodePtr)
{
	t_stack_node	*current;
	t_stack_node	*next_node;

	if (!headNodePtr || !*headNodePtr)
		return ;
	while (*headNodePtr != NULL)
	{
		current = *headNodePtr;
		next_node = (*headNodePtr)->next;
		free(current);
		*headNodePtr = next_node;
	}
	*headNodePtr = NULL;
}

void	ft_free_errors(t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		ft_free_list(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		ft_free_list(stack_b);
	ft_printf("Error\n");
	exit (1);
}
