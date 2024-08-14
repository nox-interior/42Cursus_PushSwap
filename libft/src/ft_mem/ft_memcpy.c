#include "../../inc/libft.h"

// copies n bytes from memory area src to memory area dst.
// If dst and src overlap, behavior is undefined.
// Return: a pointer to the memory location where data is copied:
// the original value of dst.

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;
	size_t			i;

	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = source[i];
		i++;
	}
	return (dst);
}
