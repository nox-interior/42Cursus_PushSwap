/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroyo <amarroyo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:30:48 by amarroyo          #+#    #+#             */
/*   Updated: 2024/08/13 14:02:41 by amarroyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

 void	ft_rev_rotate(t_stack_node **headNodePtr)
{
	t_stack_node	*node_to_rotate;
	t_stack_node	*penultimate_node;

	if (*headNodePtr == NULL || (*headNodePtr)->next == NULL)
		return ;
	node_to_rotate = *headNodePtr;
	penultimate_node = NULL;
	while (node_to_rotate->next != NULL)
	{
		penultimate_node = node_to_rotate;
		node_to_rotate = node_to_rotate->next;
	}
	if (penultimate_node != NULL)
	{
		penultimate_node->next = NULL;
		node_to_rotate->next = *headNodePtr;
		(*headNodePtr)->prev = node_to_rotate;
		*headNodePtr = node_to_rotate;
		node_to_rotate->prev = NULL;
	}
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
