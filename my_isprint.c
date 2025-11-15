#include "libmy.h"

int	my_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
