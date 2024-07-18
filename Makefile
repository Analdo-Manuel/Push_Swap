CC = gcc
CFLAGS = -Wall -Wextra -Werror
SOURCE = 	push_swap.c analise_code.c				\
			rules_one.c rules_two.c rules_three.c 	\
			libft/ft_atoi.c operation_two.c			\
			utils_one.c main.c

all:
	@$(CC) $(CFLAGS) -C $(SOURCE) -o push_swap

clean:
	rm -f push_swap

fclear:
	rm -f *~ push_swap

re:	fclear all
