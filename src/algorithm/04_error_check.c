/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarroyo <amarroyo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:47:35 by amarroyo          #+#    #+#             */
/*   Updated: 2024/08/13 14:05:55 by amarroyo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

// Ft_atoll handles the int_min in_max limits, if ft_atoi is used, it cannot
// handle overflows, returning a valid input when it isn't the case.
static long long	ft_atoll(const char *str)
{
	long long	result;
	int			sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

bool	ft_is_nbr(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (false);
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_limits(const char *str)
{
	long long	nbr;

	nbr = ft_atoll(str);
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (false);
	return (true);
}

bool	ft_check_duplicates(t_stack_node *stack, int nbr)
{
	t_stack_node	*current;

	current = stack;
	while (current)
	{
		if (current->value == nbr)
			return (false);
		current = current->next;
	}
	return (true);
}
