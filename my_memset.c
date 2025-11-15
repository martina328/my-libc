#include "libmy.h"

void	*my_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	tmp;
	size_t			i;

	ptr = (unsigned char *)s;
	tmp = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		ptr[i] = tmp;
		i++;
	}
	return (s);
}
