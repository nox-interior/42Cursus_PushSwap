#include "../../inc/libft.h"

// Erases a node an frees the allocated memory of the node, using del function.

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
