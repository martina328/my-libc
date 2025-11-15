# libmy/test/Makefile

# Compiler settings
CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I.. -L..
RM      := rm -f

.PHONY: test fclean

# Default target: build both libmy and the test
test:
	$(MAKE) -C .. list
	$(CC) $(CFLAGS) test.c -o test.out -lmy
	$(CC) $(CFLAGS) test_list.c -o test_list.out -lmy
	./test.out

fclean:
	$(MAKE) -C .. fclean
	$(RM) test.out test_list.out
