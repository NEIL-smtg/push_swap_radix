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

SRC_FILES	= main utils op_rotate op_swap_push op_reverse_rotate ft_sort ft_sort3 \
			  ft_atol ft_check_valid ft_stack ft_stack2 ft_sort5
LIBFT_DIR	= Libft/
LIBFT		= libft.a
OBJS_DIR	= objs/
NAME		= push_swap.a
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RED			:= $(shell tput -Txterm setaf 1)
RESET		:= $(shell tput -Txterm sgr0)
SRC			= $(addsuffix .c, $(SRC_FILES))
OBJS		= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(LIBFT_DIR)$(LIBFT)
	mkdir -p $(OBJS_DIR)
	make $(NAME)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	touch $(NAME)
	cp $(LIBFT_DIR)$(LIBFT) .
	mv $(LIBFT) $(NAME)
	ar -crs $(NAME) $(OBJS)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC)

clean:
	rm -rf $(OBJS)

# cd $(LIBFT_DIR) && $(MAKE) fclean
fclean: clean
	rm -rf $(OBJS_DIR)
	rm -rf $(NAME)
	clear
	@echo "removed .o .a files"

re : fclean all

run:
	make
	clear
	@gcc main.c $(NAME) -o sort
	@echo "$(RED)sort created"

runlib:
	@gcc main.c $(NAME) $(LIBFT) -o sort
	@echo "$(RED)sort created"

runfs:
	@gcc -Wall -Werror -Wextra -fsanitize=address -g main.c $(NAME) -o sort
	@echo "$(RED)fsanitize sort created"

valg:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt
