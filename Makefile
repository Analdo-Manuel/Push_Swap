NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCE = 	push_swap.c 		\
			check_input.c 		\
			rules_one.c 		\
			rules_two.c 		\
			rules_three.c 		\
			operation.c 		\
			sort/sort_one.c		\
			sort/sort_two.c		\
			sort/sort_treen.c	\
			sort/sort_four.c	\
			sort/sort_five.c	\
			utils_one.c			\
			utils_two.c
OBJ = ${SOURCE:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f sort/$(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all