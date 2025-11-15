#include "libmy.h"

char	*my_strdup(const char *src)
{
	char		*dest;
	size_t		i;

	dest = (char *) malloc((my_strlen(src) + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
