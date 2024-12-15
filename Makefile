SRC = *.c #for_now
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk.a
all : $(NAME)

$(NAME) :
	cc $(CFLAGS) server.c -o server
	cc $(CFLAGS) client.c -o client
clean :

fclean :

re : fclean all