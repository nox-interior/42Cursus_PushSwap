#include "../../inc/libft.h"

// Copies a string (src) into a destination buffer (dst) 
// while limiting the number of characters copied to the size 
// of the destination buffer.
// Return: the length of the source string

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
		return (ft_strlen(src));
	while (i < dstsize - 1 && src [i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
