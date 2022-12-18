# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/09 17:58:37 by timartin          #+#    #+#              #
#    Updated: 2022/12/09 17:58:39 by timartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap

SRCS		= srcs/push_swap.c srcs/check_arg.c srcs/struct_utils.c srcs/push_swap_utils.c srcs/check_sort.c srcs/sort_stack.c srcs/sort_small.c srcs/operations.c srcs/operations2.c srcs/operations3.c srcs/sort_big.c srcs/calculations.c srcs/calc_op.c

OBJS		= $(SRCS:.c=.o)

LIBFTA		= ./libft/libft.a

RM		= rm -f

CC		= gcc -Wall -Wextra -Werror #-g -fsanitize=address

.c.o:
			@$(CC) -c $< -o $@

all:		$(NAME)

$(NAME): 	$(LIBFTA) $(OBJS)
			$(CC) $(OBJS) $(LIBFTA) -o $(NAME)

$(LIBFTA):
			@make -C libft

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make -C libft fclean

re:			fclean all

.PHONY:		all clean re fclean