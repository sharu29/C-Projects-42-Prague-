NAME		= fractol 
SRCS		= main.c events.c init.c math_utils.c render.c string_utils.c
OBJECTS 	= $(SRCS:.c=.o)
CC		    = cc
FLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -L$(MINILIBX_DIR) -lmlx_Linux -L/usr/X11/lib -lXext -lX11 -lm 

INCS = fractol.h
MINILIBX_DIR		= ./minilibx-linux
MINILIBX = $(MINILIBX_DIR)/libmlx_Linux.a 

RM = rm -f

all		:	$(NAME)

$(NAME) : $(OBJECTS) $(INCS) 
	$(CC) $(FLAGS) $(OBJECTS) $(MLX_FLAGS) -o $(NAME)

%.o: %.c $(INCS) 
	$(CC) $(FLAGS) -c $< -o $@

clean		:	
	$(RM) $(OBJECTS)

fclean		:  clean 
	$(RM) $(NAME)

re		:	fclean all

.PHONY: all clean fclean re 
