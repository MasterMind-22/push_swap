NAME = push_swap
SRCS = help_functions.c \
	   parsing.c \
	   push_swap.c

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $? libft.a -o $(NAME)

%.o : %.c push_swap.h
	$(CC) -c $<
	cd ./libft && make && cd ..

clean :
	rm -f $(OBJS)
	cd ./libft && make clean && cd ..

fclean : clean
	rm $(NAME)
	cd ./libft && make fclean && cd ..

re : fclean all