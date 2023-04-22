MAKEFLAGS += s
NAME = push_swap
CHECKER = checker
SRCS = help_functions.c \
	   parsing.c \
	   list_funcs.c \
	   libft_utils.c \
	   ft_split.c \
	   instructions_1.c \
	   instructions_2.c \
	   instructions_3.c \
	   sort_nums_100_500.c \
	   sort_nums_3_5.c \
	   get_next_line.c \
	   get_next_line_utils.c

OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

bonus : $(CHECKER)

$(CHECKER): $(OBJS)
	$(CC) checker.c $(CFLAGS) $? -o $(CHECKER)

$(NAME): $(OBJS)
	$(CC) push_swap.c $(CFLAGS) $? -o $(NAME)

%.o : %.c push_swap.h
	$(CC) $(CFLAGS) -c $<

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME) $(CHECKER)

re : fclean all

push : 
	git add *
	git commit
	git push
.PHONY : all clean fclean re