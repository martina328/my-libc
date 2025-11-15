#include "libmy.h"

void	my_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, my_strlen(s));
	return ;
}
