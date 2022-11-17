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

SRC			= main.c utils.c op_rotate.c op_swap_push.c op_reverse_rotate.c ft_sort.c ft_sort3.c \
			  ft_atol.c ft_check_valid.c ft_stack.c ft_stack2.c
LIBFT_DIR	= Libft
LIBFT		= libft.a
OBJS		= $(SRC:.c=.o)
NAME		= push_swap.a
GCC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RED          := $(shell tput -Txterm setaf 1)
RESET 		 := $(shell tput -Txterm sgr0)

.c.o:
	$(GCC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME) : $(LIBFT_DIR)/$(LIBFT) $(OBJS)
	ar -rcs $(NAME) $(OBJS)
	cp $(LIBFT_DIR)/$(LIBFT) .
	mv $(LIBFT) $(NAME)

$(LIBFT_DIR)/$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
	cd $(LIBFT_DIR) && $(MAKE) fclean
	clear
	@echo "removed .o .a files"

re : fclean all

run:
	@gcc *.c Libft/libft.a -o sort
	@echo "$(RED)sort created"

runfs:
	@gcc -Wall -Werror -Wextra -fsanitize=address -g *.c Libft/libft.a -o sort
	@echo "$(RED)fsanitize sort created"