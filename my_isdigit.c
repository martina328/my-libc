#include "libmy.h"

int	my_isdigit(int c)
{
	if (48 <= c && c <= 57)
		return (1);
	return (0);
}
