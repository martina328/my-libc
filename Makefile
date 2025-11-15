SRCS =	my_strlen.c \
		my_strlcpy.c \
		my_strlcat.c \
		my_strchr.c \
		my_strrchr.c \
		my_strnstr.c \
		my_strncmp.c \
		my_memset.c \
		my_bzero.c \
		my_memcpy.c \
		my_memchr.c \
		my_memmove.c \
		my_memcmp.c \
		my_atoi.c \
		my_isalpha.c \
		my_isdigit.c \
		my_isalnum.c \
		my_isascii.c \
		my_isprint.c \
		my_toupper.c \
		my_tolower.c \
		my_calloc.c \
		my_strdup.c \
		my_substr.c \
		my_strjoin.c \
		my_strtrim.c \
		my_split.c \
		my_itoa.c \
		my_strmapi.c \
		my_striteri.c\
		my_putchar_fd.c \
		my_putstr_fd.c \
		my_putendl_fd.c \
		my_putnbr_fd.c
L_SRCS=	my_lstnew.c \
		my_lstadd_front.c \
		my_lstsize.c \
		my_lstlast.c \
		my_lstadd_back.c \
		my_lstdelone.c \
		my_lstclear.c \
		my_lstiter.c \
		my_lstmap.c
OBJS= $(SRCS:.c=.o)
L_OBJS= $(L_SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Werror -Wextra
RM := rm -f
NAME := libmy.a
AR := ar rcs

.PHONY: all clean fclean re bonus

ifdef WITH_LIST
    SRCS += $(L_SRCS)
    OBJS += $(L_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(L_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

list:
	$(MAKE) WITH_LIST=1
