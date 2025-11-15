#include "../libmy.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	print_title(const char *title)
{
	printf("\n===== %s =====\n", title);
}

char	plus_index(unsigned int i, char c)
{
	return (c + i);
}

void	add_index(unsigned int i, char *c)
{
	*c += i;
}

int	main(void)
{
	size_t		N;
	char		*long_str;
	char		*res;
	char		dest1[10];
	char		dest2[20] = "Hi";
	char		dest3[5] = "Hi";
	char		dest4[5] = "Hi";
	char		buf[20];
	char		src[] = "hello world";
	const char	*tests[] = {"2147483647", "-2147483648", "99999999999999999",
			"-99999999999999999", "   +42", "   -42abc", "", "+", "-", NULL};
	char		*calloc_test;
	char		*dup;
	char		**split;
	char		*mapped;
	char		iter[] = "abcd";

	N = (size_t)INT_MAX + 42u;
	long_str = malloc(N + 1);
	memset(long_str, '1', N);
	long_str[N] = '\0';
	/* my_strlen */
	print_title("my_strlen");
	printf("len('hello'): %zu, %zu\n", my_strlen("hello"), strlen("hello"));
	printf("len(''): %zu, %zu\n", my_strlen(""), strlen(""));
	printf("len('   '): %zu, %zu\n", my_strlen("   "), strlen("   "));
	printf("len(very long str): %zu, %zu\n", my_strlen(long_str),
		strlen(long_str));
	printf("strlen(NULL): Segmentation fault\n");
	/* my_strlcpy */
	print_title("my_strlcpy");
	printf("src='hello', dest size= 10 -> %zu\n", my_strlcpy(dest1, "hello",
			10));
	printf("result: %s\n", dest1);
	printf("src='hello world', dest size= 5 -> %zu\n", my_strlcpy(dest1,
			"hello world", 5));
	printf("result: %s\n", dest1);
	printf("src=very long str, dest size= 5 -> %zu\n", my_strlcpy(dest1,
			long_str, 5));
	printf("result: %s\n", dest1);
	/* my_strlcat */
	print_title("my_strlcat");
	printf("result len=%zu, dest='%s'\n", my_strlcat(dest2, " there!",
			sizeof(dest2)), dest2);
	printf("result len=%zu, dest='%s'\n", my_strlcat(dest3, " there!",
			sizeof(dest3)), dest3);
	printf("result len=%zu, dest='%s'\n", my_strlcat(dest4, long_str,
			sizeof(dest4)), dest4);
	printf("result len=%zu, dest='NULL'\n", my_strlcat(NULL, "WORLD", 0));
	printf("my_strlcat(*, NULL, *); undefined\n");
	/* my_strchr / my_strrchr */
	print_title("my_strchr / my_strrchr");
	printf("my_strchr('hello', 'l') -> %s\n", my_strchr("hello", 'l'));
	printf("my_strrchr('hello', 'l') -> %s\n", my_strrchr("hello", 'l'));
	printf("my_strchr('hello', 'x') -> %s\n", my_strchr("hello", 'x'));
	printf("my_strrchr('hello', '\\0') -> %s\n", my_strrchr("hello", '\0'));
	/* my_strnstr */
	print_title("my_strnstr");
	res = my_strnstr("abc", "abd", 2);
	printf("%s\n", res ? res : "(null)");
	res = my_strnstr("abc", "abc", 10);
	printf("%s\n", res ? res : "(null)");
	res = my_strnstr("abcd", "abc", 4);
	printf("%s\n", res ? res : "(null)");
	res = my_strnstr("a", "", 1);
	printf("%s\n", res ? res : "(null)");
	res = my_strnstr("", "", 1);
	printf("%s\n", res ? res : "(null)");
	res = my_strnstr(NULL, "\0", 1);
	printf("%s\n", res ? res : "(null)");
	res = my_strnstr(NULL, "2", 0);
	printf("%s\n", res ? res : "(null)");
	printf("strnstr(NULL, abc, 1): Segmentation fault\n");
	printf("strnstr(\\0, NULL, 1): Segmentation fault\n");
	/* my_strncmp */
	print_title("my_strncmp");
	printf("%d\n", my_strncmp("abc", "abd", 2));
	printf("%d\n", my_strncmp("abc", "abc", 10));
	printf("%d\n", my_strncmp("abcd", "abc", 4));
	printf("%d\n", my_strncmp("abcs", "", 1));
	/* my_memset / my_bzero / my_memcpy / my_memmove / my_memchr / my_memcmp */
	print_title("my_memset / my_bzero / my_memcpy / my_memmove / my_memchr / my_memcmp");
	my_memset(buf, 'A', sizeof(buf));
	printf("memset: %.*s\n", 10, buf);
	my_bzero(buf, 10);
	printf("bzero: first byte = %d\n", buf[0]);
	my_memcpy(buf, src, strlen(src) + 1);
	printf("memcpy: %s\n", buf);
	my_memmove(buf + 2, buf, strlen(buf) + 1);
	printf("memmove overlap: %s\n", buf);
	printf("memchr('world', 'r') -> %s\n", (char *)my_memchr("world", 'r', 5));
	printf("memcmp('abc','abd',3) -> %d\n", my_memcmp("abc", "abd", 3));
	/* my_atoi */
	print_title("my_atoi");
	for (int i = 0; tests[i] != NULL; i++)
	{
		printf("Input: \"%s\"\n", tests[i]);
		printf("  my_atoi: %d\n", my_atoi(tests[i]));
		printf("  atoi   : %d\n", atoi(tests[i]));
	}
	printf("Input: \"very long str\"\n");
	printf("  my_atoi: %d\n", my_atoi(long_str));
	printf("  atoi   : %d\n", atoi(long_str));
	printf("atoi(NULL): Segmentation fault\n");
	/* my_isalpha / isdigit / isalnum / isascii / isprint */
	print_title("my_is*");
	printf("my_isalpha('A'): %d\n", my_isalpha('A'));
	printf("my_isdigit('3'): %d\n", my_isdigit('3'));
	printf("my_isalnum('z'): %d\n", my_isalnum('z'));
	printf("my_isascii(128): %d\n", my_isascii(128));
	printf("my_isprint(31): %d\n", my_isprint(31));
	/* my_toupper / my_tolower */
	print_title("my_toupper / my_tolower");
	printf("%c -> %c\n", 'a', my_toupper('a'));
	printf("%c -> %c\n", 'Z', my_tolower('Z'));
	/* my_calloc / my_strdup */
	print_title("my_calloc / my_strdup");
	calloc_test = my_calloc(5, sizeof(char));
	if (calloc_test)
	{
		printf("calloc first bytes: %d %d %d %d %d\n", calloc_test[0],
			calloc_test[1], calloc_test[2], calloc_test[3], calloc_test[4]);
		free(calloc_test);
	}
	dup = my_strdup("libmy");
	printf("strdup: %s\n", dup);
	free(dup);
	/* my_substr / my_strjoin / my_strtrim */
	print_title("my_substr / my_strjoin / my_strtrim");
	printf("substr('', -1, -1): %s\n", my_substr("", -1, -1));
	printf("substr('www', -1, 0): %s\n", my_substr("www", -1, 0));
	printf("substr('libmy', 0, -1): %s\n", my_substr("libmy", 0, -1));
	printf("substr('hello', 1, 3): %s\n", my_substr("hello", 1, 3));
	printf("strjoin('hello','world'): %s\n", my_strjoin("hello", "world"));
	printf("strtrim('  hello  ', ' '): %s\n", my_strtrim("  hello  ", " "));
	printf("strtrim("
			", "
			"): %s\n",
			my_strtrim("", ""));
	/* my_split */
	print_title("my_split");
	split = my_split("  hello  world test  ", ' ');
	for (int i = 0; split && split[i]; i++)
	{
		printf("[%d]: %s\n", i, split[i]);
		free(split[i]);
	}
	free(split);
	/* my_itoa */
	print_title("my_itoa");
	printf("%s\n", my_itoa(INT_MAX));
	printf("%s\n", my_itoa(INT_MIN));
	printf("%s\n", my_itoa(0));
	printf("%s\n", my_itoa(-42));
	/* my_strmapi / my_striteri */
	print_title("my_strmapi / my_striteri");
	mapped = my_strmapi("abcd", plus_index);
	printf("strmapi: %s\n", mapped);
	free(mapped);
	my_striteri(iter, add_index);
	printf("striteri: %s\n", iter);
	/* my_put* */
	print_title("my_put*");
	my_putchar_fd('A', 1);
	my_putstr_fd("BC", 1);
	my_putendl_fd("DE", 1);
	my_putnbr_fd(2147483647, 1);
	my_putnbr_fd(-2147483648, 1);
	my_putnbr_fd(0, 1);
	my_putnbr_fd(1, 1);
	my_putnbr_fd(-1, 1);
	write(1, "\n", 1);
	return (0);
}
