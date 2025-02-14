NAME		= push_swap
SRCS		= main.c \
				cmd_push.c \
				cmd_rev_rotate.c \
				cmd_rotate.c \
				cmd_swap.c \
				error_utils.c \
				split.c \
				stack_utils.c \
				stack_init.c \
				tiny_sort.c \
				push_swap_init.c \
				push_swap.c 

OBJECTS 	= $(SRCS:.c=.o)
CC		    = cc
FLAGS		= -Wall -Wextra -Werror

RM = rm -f

all		:	$(NAME)

$(NAME) : $(OBJECTS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJECTS)

clean		:	
	$(RM) $(OBJECTS)

fclean		:  clean 
	$(RM) $(NAME)

re		:	fclean all

.PHONY: all clean fclean re 