NAME = push_swap

NAME_BONUS = checker

CC = gcc

FLAG = -Wall -Wextra -Werror

RM = rm -rf

SRC = main.c\
		start_functions.c\
		push_n_swap.c\
		start_functions_2.c\
		rotate.c\
		r_rotate.c\
		algoritm.c\
		small_sort.c\
		free.c\
		../libft/libft.a

SRC_BONUS = ../checker/main.c\
				../checker/start_functions.c\
				../checker/start_functions_2.c\
				../checker/push_n_swap.c\
				../checker/rotate.c\
				../checker/r_rotate.c\
				../checker/checker_utils.c\
				../checker/free.c\
				../libft/libft.a\
				../gnl/gnl.a\

all : $(NAME)

$(NAME) :
		make all -C ../libft
		$(CC) $(SRC) -o $(NAME) $(FLAG)

bonus :
		make -C ../libft
		make -C ../gnl
		$(CC) $(SRC_BONUS) -o $(NAME_BONUS) $(FLAG)

clean :
		make clean -C ../libft

fclean :
		$(RM) $(NAME)
		$(RM) $(NAME_BONUS)
		make fclean -C ../libft
		make fclean -C ../gnl

re : fclean all

