SRC_A = ./src/ft_putchar.c ./src/ft_putnbr.c ./src/ft_putstr.c ./src/ft_atoi.c
CFLAGS = -Wall -Wextra -Werror
SRC_CM = client.c
SRC_CB = client_bonus.c
SRC_SM = server.c
SRC_SB = server_bonus.c

OBJ_A = $(SRC_A:.c=.o)
OBJ_CM = $(SRC_CM:.c=.o)
OBJ_CB = $(SRC_CB:.c=.o)
OBJ_SM = $(SRC_SM:.c=.o)
OBJ_SB = $(SRC_SB:.c=.o)

NAME_SERVER = server
NAME_CLIENT = client
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

all : $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT) : $(OBJ_A) $(OBJ_CM)
	cc $(CFLAGS) $(OBJ_A) $(OBJ_CM) -o $(NAME_CLIENT)

$(NAME_SERVER) : $(OBJ_A) $(OBJ_SM)
	cc $(CFLAGS) $(OBJ_A) $(OBJ_SM) -o $(NAME_SERVER)

$(NAME_CLIENT_BONUS) : $(OBJ_A) $(OBJ_CB)
	cc $(CFLAGS) $(OBJ_CB) $(OBJ_A) -o $(NAME_CLIENT_BONUS)
	rm -f client_bonus.o

$(NAME_SERVER_BONUS) : $(OBJ_A) $(OBJ_SB)
	cc $(CFLAGS) $(OBJ_SB) $(OBJ_A) -o $(NAME_SERVER_BONUS)
	rm -f server_bonus.o

bonus :	$(OBJ_A) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

clean :
	rm -f $(OBJ_A) $(OBJ_CB) $(OBJ_CM) $(OBJ_SB) $(OBJ_SM) server client server_bonus client_bonus

fclean : clean

re : fclean all

re_bonus : fclean bonus
