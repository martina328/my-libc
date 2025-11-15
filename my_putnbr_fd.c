#include "libmy.h"

static void	my_putpositive(int nb, int fd)
{
	int		i;
	char	c;

	if (fd < 0)
		return ;
	i = 1000000000;
	while (i > nb && i != 1)
		i = i / 10;
	while (i >= 1)
	{
		c = '0' + (nb / i);
		write(fd, &c, 1);
		nb = nb % i;
		i = i / 10;
	}
	return ;
}

void	my_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	else if (-2147483648 < nb && nb < 0)
	{
		write(fd, "-", 1);
		nb = -nb;
	}
	my_putpositive(nb, fd);
	return ;
}
