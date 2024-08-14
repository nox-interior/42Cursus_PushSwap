#include "../../inc/ft_printf.h"

int	ft_print_nbr(int nbr)
{
	int	printlen;

	printlen = 0;
	if (nbr == INT_MIN)
	{
		printlen += ft_print_str("-2147483648");
		return (printlen);
	}
	if (nbr < 0)
	{
		printlen += ft_print_char('-');
		nbr = -nbr;
	}
	if (nbr > 9)
		printlen += ft_print_nbr(nbr / 10);
	printlen += ft_print_char(nbr % 10 + '0');
	return (printlen);
}
