#include "libmy.h"

void	my_bzero(void *s, size_t n)
{
	s = my_memset(s, '\0', n);
	return ;
}
