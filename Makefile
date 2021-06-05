NAME = push_swap

NAME2 = checker

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = 	main.c\
		./libft/ft_memset.c\
		./libft/ft_atoi.c\
		srcs/util.c\
		srcs/util2.c\
		cmd.c\
		cmd2.c\
		three.c\
		five.c\
		./libft/ft_strchr.c\
		./libft/ft_split.c\
		hundred1.c\
		hundred2.c\
		hundred3.c\
		hundred4.c\
		build.c

SRCS_CK =	checker.c\
			gnl/get_next_line.c\
			gnl/get_next_line_utils.c\
			./libft/ft_strchr.c\
			./libft/ft_strstr.c\
			./libft/ft_memset.c\
			./libft/ft_atoi.c\
			./libft/ft_split.c\
			srcs/util.c\
			srcs/util2.c\
			cmd.c\
			cmd2.c\
			build.c

all : $(NAME) $(NAME2)

$(NAME) :
	make all -C libft
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)

$(NAME2) :
	make all -C libft
	$(CC) $(CFLAGS) -o $(NAME2) $(SRCS_CK)


fclean : clean
	$(RM) $(NAME) $(NAME2)
	make fclean -C libft/

clean :
	$(RM) $(NAME) $(NAME2)
	make clean -C libft/

re_$(NAME) : fclean $(NAME)

re_$(NAME2) : fclean $(NAME2)

re : fclean all

