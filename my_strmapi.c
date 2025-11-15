#include "libmy.h"

char	*my_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	if (!s || !f)
		return (NULL);
	new = malloc((my_strlen(s) + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		new[i] = f((unsigned int)i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
