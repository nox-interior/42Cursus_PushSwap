#include "../../inc/libft.h"

// Locates the first occurence of c (converted to an unsigned char)
// in string s; Scans the initial n bytes of s for the first instance of c.
// Return: a pointer to the byte located, or NULL if no such byte exists 
// within the n bytes.

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
