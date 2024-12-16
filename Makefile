SRC = ft_putchar.c ft_putnbr.c ft_putstr.c
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk.a

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(CFLAGS) server.c $(SRC) -o server
	cc $(CFLAGS) client.c $(SRC) -o client

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all