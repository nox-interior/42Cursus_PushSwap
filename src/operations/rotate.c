/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroyo <amarroyo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:30:30 by amarroyo          #+#    #+#             */
/*   Updated: 2024/08/13 12:16:05 by amarroyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	ft_rotate(t_stack_node **headNodePtr)
{
	t_stack_node	*node_to_rotate;
	t_stack_node	*last_node;

	if (*headNodePtr == NULL || (*headNodePtr)->next == NULL)
		return ;
	node_to_rotate = *headNodePtr;
	last_node = *headNodePtr;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = node_to_rotate;
	*headNodePtr = node_to_rotate->next;
	node_to_rotate->next->prev = NULL;
	node_to_rotate->next = NULL;
	node_to_rotate->prev = last_node;
}

void	ft_ra(t_stack_node **stack_node)
{
	ft_rotate(stack_node);
	ft_printf("ra\n");
}

void	ft_rb(t_stack_node **stack_node)
{
	ft_rotate(stack_node);
	ft_printf("rb\n");
}

void	ft_rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	ft_printf("rr\n");
}
