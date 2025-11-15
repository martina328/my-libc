#include "libmy.h"

void	my_putendl_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, my_strlen(s));
	write(fd, "\n", 1);
	return ;
}
