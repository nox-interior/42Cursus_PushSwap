#include "../../inc/libft.h"

// Sends character c to the specified file descriptor

void	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return ;
	write(fd, &c, 1);
}
