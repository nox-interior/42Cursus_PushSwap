#include "../../inc/push_swap.h"

void	ft_calculate_moves(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*temp_b;
	int				len_a;
	int				len_b;

	if (!*stack_a || !*stack_b)
		return ;
	temp_b = *stack_b;
	len_a = ft_stack_len(*stack_a);
	len_b = ft_stack_len(*stack_b);
	while (temp_b)
	{
		if (temp_b->position <= len_b / 2)
			temp_b->moves_b = temp_b->position;
		else
			temp_b->moves_b = (len_b - temp_b->position) * -1;
		if (temp_b->target_pos <= len_a / 2)
			temp_b->moves_a = temp_b->target_pos;
		else
			temp_b->moves_a = (len_a - temp_b->target_pos) * -1;
		temp_b = temp_b->next;
	}
}

static void	ft_move_both(t_stack_node **stack_a, t_stack_node **stack_b,
							int *moves_a, int *moves_b)
{
	while (*moves_a > 0 && *moves_b > 0)
	{
		ft_rr(stack_a, stack_b);
		(*moves_a)--;
		(*moves_b)--;
	}
	while (*moves_a < 0 && *moves_b < 0)
	{
		ft_rrr(stack_a, stack_b);
		(*moves_a)++;
		(*moves_b)++;
	}
}

static void	ft_move_stack_a(t_stack_node **stack_a, int *moves_a)
{
	while (*moves_a != 0)
	{
		if (*moves_a > 0)
		{
			ft_ra(stack_a);
			(*moves_a)--;
		}
		else
		{
			ft_rra(stack_a);
			(*moves_a)++;
		}
	}
}

static void	ft_move_stack_b(t_stack_node **stack_b, int *moves_b)
{
	while (*moves_b != 0)
	{
		if (*moves_b > 0)
		{
			ft_rb(stack_b);
			(*moves_b)--;
		}
		else
		{
			ft_rrb(stack_b);
			(*moves_b)++;
		}
	}
}

void	ft_move_node(t_stack_node **stack_a, t_stack_node **stack_b,
					int moves_a, int moves_b)
{
	ft_move_both(stack_a, stack_b, &moves_a, &moves_b);
	ft_move_stack_a(stack_a, &moves_a);
	ft_move_stack_b(stack_b, &moves_b);
	ft_pa(stack_a, stack_b);
}
