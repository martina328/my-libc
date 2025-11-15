#include "libmy.h"

static int	is_set(char const c, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if ((unsigned char)c == (unsigned char)set[j])
			return (1);
		j++;
	}
	return (0);
}

char	*my_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && is_set(s1[start], set) == 1)
		start++;
	if (s1[start] == '\0')
		return (my_strdup(""));
	end = my_strlen(s1) - 1;
	while (end > start && is_set(s1[end], set) == 1)
		end--;
	trimmed = (char *)malloc((end - start + 2) * sizeof(char));
	if (trimmed == NULL)
		return (NULL);
	my_strlcpy(trimmed, s1 + start, end - start + 2);
	return (trimmed);
}
