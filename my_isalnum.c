#include "libmy.h"

int	my_isalnum(int c)
{
	if (my_isdigit(c) || my_isalpha(c))
		return (1);
	return (0);
}
