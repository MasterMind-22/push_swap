NAME = push_swap
SRCS = help_functions.c \
	   parsing.c \
	   push_swap.c \
	   list_funcs.c \
	   libft_utils.c \
	   ft_split.c \
	   instructions.c \
	   sort_number.c 

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $? -o $(NAME)

%.o : %.c push_swap.h
	$(CC) -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

push : 
	git add *
	git commit
	git push
.PHONY : all clean fclean re