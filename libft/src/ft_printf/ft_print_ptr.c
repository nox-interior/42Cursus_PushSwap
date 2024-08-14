#include "../../inc/ft_printf.h"

int	ft_print_ptr(uintptr_t nbr)
{
	int		printlen;
	char	*lower_case;

	lower_case = "0123456789abcdef";
	printlen = 0;
	if (nbr < 16)
		printlen += ft_print_char(lower_case[nbr]);
	else
	{
		printlen += ft_print_ptr(nbr / 16);
		printlen += ft_print_char(lower_case[nbr % 16]);
	}
	return (printlen);
}
