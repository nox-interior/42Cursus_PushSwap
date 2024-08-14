#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	void	*new_value;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	temp = NULL;
	while (lst)
	{
		new_value = f(lst->content);
		temp = ft_lstnew(new_value);
		if (!temp)
		{
			del (new_value);
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, temp);
		lst = lst->next;
	}
	return (new_lst);
}
