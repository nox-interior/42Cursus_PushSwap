/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroyo <amarroyo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 10:22:26 by amarroyo          #+#    #+#             */
/*   Updated: 2024/08/13 13:55:34 by amarroyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	ft_push_swap(t_stack_node **stack_a, t_stack_node **stack_b,
					int stack_len)
{
	if (stack_len == 2 && !ft_sorted_stack(*stack_a))
		ft_sa(stack_a);
	else if (stack_len == 3 && !ft_sorted_stack(*stack_a))
		ft_three_nodes_sort(stack_a);
	else if (stack_len > 3 && !ft_sorted_stack(*stack_a))
		ft_big_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	int				stack_len;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
	{
		ft_printf("Error\n");
		return (0);
	}
	stack_a = *ft_init_stack(&stack_a, argc, argv);
	if (!stack_a)
	{
		ft_printf("Error\n");
		return (1);
	}
	stack_len = ft_stack_len(stack_a);
	ft_assign_index(&stack_a);
	ft_push_swap(&stack_a, &stack_b, stack_len);
	ft_free_list(&stack_a);
	ft_free_list(&stack_b);
	return (0);
}
