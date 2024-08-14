#include "../../inc/ft_printf.h"

int	ft_print_str(char *str)
{
	int	printlen;
	int	i;

	printlen = 0;
	i = 0;
	if (!str)
		printlen += write(1, "(null)", 6);
	else
	{
		while (str[i] != '\0')
		{
			printlen += ft_print_char(str[i]);
			i++;
		}
	}
	return (printlen);
}
