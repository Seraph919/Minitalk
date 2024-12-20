SRC = ./src/ft_putchar.c ./src/ft_putnbr.c ./src/ft_putstr.c ./src/ft_atoi.c
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:.c=.o)
NAME = minitalk.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(?)
	cc $(CFLAGS) server.c $(NAME) -o server 
	cc $(CFLAGS) client.c $(NAME) -o client

bonus :	$(OBJ)
	ar -rcs $(NAME) $(?)
	cc $(CFLAGS) server_bonus.c $(NAME) -o server_bonus
	cc $(CFLAGS) client_bonus.c $(NAME) -o client_bonus

clean :
	rm -f $(OBJ) server client server_bonus client_bonus

fclean : clean
	rm -f $(NAME) 

re : fclean all
