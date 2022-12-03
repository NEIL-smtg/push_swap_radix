# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: suchua <suchua@student.42kl.edu.my>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 17:20:08 by suchua            #+#    #+#              #
#    Updated: 2022/11/15 14:44:14 by suchua           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR		= srcs/
SRC			= main utils op_rotate op_swap_push op_reverse_rotate ft_sort ft_sort3 \
			  my_atoi ft_check_valid ft_check_valid_utils ft_stack ft_stack2 ft_sort5 \
			  ft_sort_infinity normalize97
BONUS_SRC1	= utils op_rotate op_swap_push op_reverse_rotate ft_sort ft_sort3 \
			  my_atoi ft_check_valid ft_check_valid_utils ft_stack ft_stack2 ft_sort5 \
			  ft_sort_infinity normalize97
BONUS_SRC2	= main.c
SRCS_N_MAIN	= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_N_MAIN)))
HEADER		= $(SRC_DIR)push_swap.h 
SRCS		= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC)))
OBJS_DIR	= objs/
OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC)))
LIBFT_DIR	= Libft
LIBFT		= libft.a
NAME		= push_swap.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RED			:= $(shell tput -Txterm setaf 1)
RESET		:= $(shell tput -Txterm sgr0)

all:
	mkdir -p $(OBJS_DIR)
	make do

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

do: $(NAME)

$(NAME) : $(LIBFT_DIR)/$(LIBFT) $(OBJS)
	touch $(NAME)
	cp $(LIBFT_DIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar -crs $(NAME) $(OBJS)
	make run
	clear
	@echo "$(RED)fsanitize sort created"

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

del:
	rm $(NAME)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRCS)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)
	cd $(LIBFT_DIR) && $(MAKE) fclean
	clear
	@echo "removed .o .a files"

run:
	@$(CC) $(CFLAGS) -fsanitize=address -g $(SRCS) $(NAME) -o push_swap

runb:
	@$(CC) $(CFLAGS) -fsanitize=address -g $(BONUS_DIR)main.c $(BONUS_NAME) -o checker

valg:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt

tester:
	cd push_swap_tester && bash basic_test.sh