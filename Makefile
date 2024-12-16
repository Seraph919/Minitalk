SRC = check_char.c  ft_putchar_fd.c p_memory.c formats.c ft_putnbr_fd.c unsigned.c ft_printf.c ft_putstr_fd.c upper_hexa.c p_hexa.c
OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = minitalk.a

all : $(NAME)

$(NAME) : $(OBJ)
	ar -rcs $(NAME) $(?)
	cc $(CFLAGS) server.c -o server
	cc $(CFLAGS) client.c -o client

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all