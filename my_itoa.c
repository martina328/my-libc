#include "libmy.h"
#include <stdio.h>

static void	fill_str(int n, size_t len, char *str, int minus)
{
	long long	nbr;

	nbr = n;
	if (n < 0)
	{
		str[0] = '-';
		minus = 1;
		nbr = -nbr;
	}
	str[len + minus] = '\0';
	len--;
	while (len > 0)
	{
		str[len + minus] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	str[len + minus] = (nbr % 10) + '0';
}

char	*my_itoa(int n)
{
	char	*str;
	size_t	len;
	int		minus;
	int		magnitude;

	minus = 0;
	magnitude = n;
	len = 1;
	while (magnitude < -9 || 9 < magnitude)
	{
		magnitude /= 10;
		len++;
	}
	if (n < 0)
		str = (char *)malloc((len + 2) * sizeof(char));
	else
		str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	fill_str(n, len, str, minus);
	return (str);
}
