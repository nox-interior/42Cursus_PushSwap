#include "../../inc/ft_printf.h"

int	ft_print_hex(long nbr, int is_uppercase)
{
	int		printlen;
	char	*lower_case;
	char	*upper_case;

	lower_case = "0123456789abcdef";
	upper_case = "0123456789ABCDEF";
	printlen = 0;
	if (nbr < 16)
	{
		if (is_uppercase)
			printlen += ft_print_char(upper_case[nbr]);
		else
			printlen += ft_print_char(lower_case[nbr]);
	}
	else
	{
		printlen += ft_print_hex(nbr / 16, is_uppercase);
		if (is_uppercase)
			printlen += ft_print_char(upper_case[nbr % 16]);
		else
			printlen += ft_print_char(lower_case[nbr % 16]);
	}
	return (printlen);
}
