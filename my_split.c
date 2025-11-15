#include "libmy.h"

static size_t	count_words(char const *s, char c)
{
	size_t	c_words;
	size_t	i;

	i = 0;
	c_words = 0;
	while (s[i] != '\0')
	{
		while (s[i] && (unsigned char)s[i] == (unsigned char)c)
			i++;
		if (s[i])
			c_words++;
		while (s[i] && (unsigned char)s[i] != (unsigned char)c)
			i++;
	}
	return (c_words);
}

static void	free_words(char **words)
{
	size_t	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
	return ;
}

static char	**fill_words(char const *s, char c, char **words, size_t c_words)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (i < c_words)
	{
		while (s[j] && (unsigned char)s[j] == (unsigned char)c)
			j++;
		len = 0;
		while (s[j + len] && (unsigned char)s[j + len] != (unsigned char)c)
			len++;
		words[i] = (char *)malloc((len + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			free_words(words);
			return (NULL);
		}
		my_strlcpy(words[i], s + j, len + 1);
		j = j + len;
		i++;
	}
	words[i] = NULL;
	return (words);
}

char	**my_split(char const *s, char c)
{
	char	**words;
	size_t	c_words;

	if (!s)
		return (NULL);
	c_words = count_words(s, c);
	words = malloc((c_words + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	return (fill_words(s, c, words, c_words));
}
