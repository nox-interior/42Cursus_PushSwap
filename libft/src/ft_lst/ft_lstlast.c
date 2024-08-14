#include "../../inc/libft.h"

// Returns the last node of the list

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*second_last;

	second_last = lst;
	if (!lst)
		return (NULL);
	if (lst->next == NULL)
		return (lst);
	while (second_last->next->next != NULL)
	{
		second_last = second_last->next;
	}
	return (second_last->next);
}
