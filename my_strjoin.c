#include "libmy.h"

static char	*fill_dest(char const *s1, char const *s2, char *dest)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
	{
		dest[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*my_strjoin(char const *s1, char const *s2)
{
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	dest = (char *)malloc((my_strlen(s1) + my_strlen(s2) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	dest = fill_dest(s1, s2, dest);
	return (dest);
}
