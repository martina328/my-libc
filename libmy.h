#ifndef LIBMY_H
# define LIBMY_H

# include <limits.h> // INT_MAX, INT_MIN, LONG_MAX, LONG_MIN
# include <stddef.h> // size_t
# include <stdint.h> // SIZE_MAX
# include <stdlib.h> // malloc, free
# include <unistd.h> // write

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int					my_atoi(const char *nptr);
void				my_bzero(void *s, size_t n);
void				*my_calloc(size_t nmemb, size_t size);
int					my_isalnum(int c);
int					my_isalpha(int c);
int					my_isascii(int c);
int					my_isdigit(int c);
int					my_isprint(int c);
char				*my_itoa(int n);
void				my_lstadd_back(t_list **lst, t_list *new);
void				my_lstadd_front(t_list **lst, t_list *new);
void				my_lstclear(t_list **lst, void (*del)(void *));
void				my_lstdelone(t_list *lst, void (*del)(void *));
void				my_lstiter(t_list *lst, void (*f)(void *));
t_list				*my_lstlast(t_list *lst);
t_list				*my_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));
t_list				*my_lstnew(void *content);
int					my_lstsize(t_list *lst);
void				*my_memchr(const void *s, int c, size_t n);
int					my_memcmp(const void *s1, const void *s2, size_t n);
void				*my_memcpy(void *dest, const void *src, size_t n);
void				*my_memmove(void *dest, const void *src, size_t n);
void				*my_memset(void *s, int c, size_t n);
void				my_putchar_fd(char c, int fd);
void				my_putendl_fd(char *s, int fd);
void				my_putnbr_fd(int n, int fd);
void				my_putstr_fd(char *s, int fd);
char				**my_split(char const *s, char c);
char				*my_strchr(const char *s, int c);
char				*my_strdup(const char *src);
void				my_striteri(char *s, void (*f)(unsigned int, char *));
char				*my_strjoin(char const *s1, char const *s2);
size_t				my_strlcat(char *dest, const char *src, size_t size);
size_t				my_strlcpy(char *dst, const char *src, size_t size);
size_t				my_strlen(const char *str);
char				*my_strmapi(char const *s, char (*f)(unsigned int, char));
int					my_strncmp(const char *s1, const char *s2, size_t n);
char				*my_strnstr(const char *big, const char *little,
						size_t len);
char				*my_strrchr(const char *s, int c);
char				*my_strtrim(char const *s1, char const *set);
char				*my_substr(char const *s, unsigned int start, size_t len);
int					my_tolower(int c);
int					my_toupper(int c);
#endif
