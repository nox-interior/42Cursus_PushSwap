#include "../../inc/libft.h"

// converts upper-case into lower-case
// return: if the argument is upper-case, its lower-case.
// return: if the argument is not upper-case, returns the original c.

int	ft_tolower(int c)
{
	int	lower;

	lower = (c + 32);
	if (c >= 'A' && c <= 'Z')
	{
		return (lower);
	}
	return (c);
}
