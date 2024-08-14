#include "../../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*current_node;

	if (!new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		current_node = *lst;
		while (current_node->next != NULL)
		{
			current_node = current_node->next;
		}
		current_node->next = new_node;
	}
}
