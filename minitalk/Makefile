SERVER = server
CLIENT = client

SRC_SERVER = server.c 
SRC_CLIENT = client.c 

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

COMPILER = cc
CFLAGS = -Wall -Wextra -Werror

INCS = minitalk.h

LIBFT_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libftprintf.a

RM = rm -f 

all: $(CLIENT) $(SERVER)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(CLIENT): $(OBJ_CLIENT) $(INCS) $(LIBFT)
	 $(COMPILER) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER) $(INCS) $(LIBFT)
	 $(COMPILER) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(SERVER)

clean:
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(CLIENT) $(SERVER)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean  re .c .o
