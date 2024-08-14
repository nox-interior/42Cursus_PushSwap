#include "../../inc/libft.h"

// used to allocate a block of contiguous memory for a specified 
// number of objects, each of a specified size.
// and sets them to '0'.
// Return: a pointer to the allocated memory. 

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
