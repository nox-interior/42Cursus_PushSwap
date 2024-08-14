#include "../../inc/ft_printf.h"

int	ft_print_unsint(unsigned int nbr)
{
	int	printlen;

	printlen = 0;
	if (nbr > 9)
		printlen += ft_print_unsint(nbr / 10);
	printlen += ft_print_char(nbr % 10 + '0');
	return (printlen);
}
