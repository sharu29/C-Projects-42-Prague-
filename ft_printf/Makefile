SRCS = ft_printf.c ft_utils1.c ft_utils2.c

OBJS = $(SRCS:.c=.o)

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -I.

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
				ar rcs $(NAME) $(OBJS)

clean: 
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean: 		clean
						$(RM) $(NAME)

re:						fclean $(NAME)

.PHONY:			all clean fclean re