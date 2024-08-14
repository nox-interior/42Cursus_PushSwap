#include "../../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*store_next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		store_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = store_next;
	}
}
