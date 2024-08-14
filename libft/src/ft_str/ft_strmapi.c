#include "../../inc/libft.h"

// Applies 'f' to each character in 's'
// 'f' parameters: an index to each character within s, a char that represents
// an indivisul character for m the input 's'
// 'f' return: a char
//	Return: a new string, allocated with malloc.

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
