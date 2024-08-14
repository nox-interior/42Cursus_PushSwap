#include "../../inc/libft.h"

// Converts lower-case to the corresponding upper-case
// Return: if the argument is a lower-case letter it returns the upper-case
// Return: otherwise the argument is returned unchanged.

int	ft_toupper(int c)
{
	int	upper;

	upper = (c - 32);
	if (c >= 'a' && c <= 'z')
	{
		return (upper);
	}
	return (c);
}
