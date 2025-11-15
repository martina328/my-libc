#include "libmy.h"

void	*my_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (src == dest)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (dest <= src)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	return (dest);
}
