MAKEFLAGS += s
NAME = push_swap
SRCS = help_functions.c \
	   parsing.c \
	   push_swap.c \
	   list_funcs.c \
	   libft_utils.c \
	   ft_split.c \
	   instructions_1.c \
	   instructions_2.c \
	   instructions_3.c \
	   sort_nums_100_500.c \
	   sort_nums_3_5.c

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -O1 #-g -fsanitize=address -static-libsan


all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $? -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $<

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