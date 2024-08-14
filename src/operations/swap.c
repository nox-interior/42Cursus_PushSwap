/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroyo <amarroyo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 14:30:09 by amarroyo          #+#    #+#             */
/*   Updated: 2024/08/13 12:17:03 by amarroyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
