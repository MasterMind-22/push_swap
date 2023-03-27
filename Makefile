NAME = push_swap
SRCS = help_functions.c \
	   parsing.c \
	   push_swap.c \
	   list_funcs.c \
	#    ./libft/ft_strjoin.c

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $? libft.a -o $(NAME)

%.o : %.c push_swap.h
	$(CC) -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm $(NAME)

re : fclean all