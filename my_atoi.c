#include "libmy.h"

static int	is_space(int c)
{
	if ((9 <= c && c <= 13) || c == ' ')
		return (1);
	return (0);
}

static int	parse_num(const char *nptr, unsigned int i, const int sign)
{
	unsigned long long	num;

	num = 0;
	while (nptr[i] && '0' <= nptr[i] && nptr[i] <= '9')
	{
		if (num != 0)
			num *= 10;
		num += nptr[i] - '0';
		if (num > 2147483647 && sign == 1)
			return ((int)LONG_MAX);
		else if (num > 2147483648 && sign == -1)
			return ((int)LONG_MIN);
		i++;
	}
	return ((int)(num * sign));
}

int	my_atoi(const char *nptr)
{
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	while (is_space(nptr[i]))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	return (parse_num(nptr, i, sign));
}
