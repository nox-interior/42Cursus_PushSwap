#include "../../inc/libft.h"

// Fill a byte string with a byte value
// Sets len bytes of memory at the address pointed to by b to the value c
// Return: its first argument (b)
// ex: AAAAAAA

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;
	size_t			i;

	str = b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (b);
}
