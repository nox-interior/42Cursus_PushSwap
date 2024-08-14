/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_big_sort_optimal_move.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroyo <amarroyo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:47:03 by amarroyo          #+#    #+#             */
/*   Updated: 2024/08/13 13:48:01 by amarroyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	ft_abs(int nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}

void	ft_do_optimal_move(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp_b;
	int				optimal;
	int				moves_a;
	int				moves_b;

	temp_b = *stack_b;
	optimal = INT_MAX;
	if (!*stack_a || !*stack_b)
		return ;
	while (temp_b)
	{
		if (ft_abs(temp_b->moves_b) + ft_abs(temp_b->moves_a) < optimal)
		{
			optimal = ft_abs(temp_b->moves_b) + ft_abs(temp_b->moves_a);
			moves_b = temp_b->moves_b;
			moves_a = temp_b->moves_a;
		}
		temp_b = temp_b->next;
	}
	ft_move_node(stack_a, stack_b, moves_a, moves_b);
}
