#include "../../inc/push_swap.h"

static t_stack_node	*ft_stack_new(int nbr)
{
	t_stack_node	*new_node;

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
		return (NULL);
	if (new_node != NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	new_node->value = nbr;
	new_node->index = -1;
	new_node->position = -1;
	new_node->target_pos = -1;
	new_node->moves_a = -1;
	new_node->moves_b = -1;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

static void	ft_add_to_bottom(t_stack_node **stack_a, int nbr)
{
	t_stack_node	*new_node;
	t_stack_node	*last_node;

	new_node = ft_stack_new(nbr);
	if (!*stack_a)
		*stack_a = new_node;
	else
	{
		last_node = *stack_a;
		while (last_node->next != NULL)
			last_node = last_node->next;
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

static void	ft_free_substrings(char **substrings)
{
	int	i;

	i = 0;
	if (substrings)
	{
		while (substrings[i])
		{
			free(substrings[i]);
			i++;
		}
		free(substrings);
	}
}

t_stack_node	**ft_init_stack(t_stack_node **stack_a, int argc, char **argv)
{
	int		i;
	int		j;
	char	**substrings;
	int		nbr;

	i = 1;
	while (i < argc)
	{
		substrings = ft_split(argv[i], ' ');
		j = 0;
		while (substrings[j])
		{
			if (!ft_is_nbr(substrings[j]) || !ft_check_limits(substrings[j]))
				ft_free_errors(stack_a, NULL);
			nbr = ft_atoi(substrings[j]);
			if (!ft_check_duplicates(*stack_a, nbr))
				ft_free_errors(stack_a, NULL);
			ft_add_to_bottom(stack_a, nbr);
			j++;
		}
		ft_free_substrings(substrings);
		i++;
	}
	return (stack_a);
}
