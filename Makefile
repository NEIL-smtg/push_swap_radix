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
			  my_atoi ft_check_valid ft_check_valid_utils ft_stack ft_stack2 ft_sort5 \
			  ft_sort_infinity normalize97
SRC_NMAIN	= utils.c op_rotate.c op_swap_push.c op_reverse_rotate.c ft_sort.c ft_sort3.c \
			  my_atoi.c ft_check_valid.c ft_check_valid_utils.c ft_stack.c ft_stack2.c ft_sort5.c \
			  ft_sort_infinity.c normalize97.c
BONUS_o2	= $(SRC_NMAIN:.c=.o)
BONUS_DIR	= bonus/
BONUS_FILES = bonus/main.c
BONUS_o		= $(BONUS_FILES:.c=.o)
BONUS_LIB	= checker
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
FS			= -fsanitize=address -g

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

rere:
	$(CC) $(CFLAGS) $(FS) $(SRC_NMAIN) $(BONUS_FILES) $(LIBFT_DIR)$(LIBFT) -o checker

fcleanb:
	rm -rf $(BONUS_o2)

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(OBJS_DIR)
	rm -rf $(NAME)
	cd $(LIBFT_DIR) && $(MAKE) fclean
	clear
	@echo "removed .o .a files"


re : fclean all

run:
	make
	clear
	@gcc main.c $(NAME) -o sort
	@echo "$(RED)sort created"

runlib:
	make
	@gcc main.c $(NAME) $(LIBFT) -o push_swap
	@echo "$(RED)sort created"

runfs:
	make
	@gcc -Wall -Werror -Wextra -fsanitize=address -g main.c $(NAME) -o push_swap
	clear
	@echo "$(RED)fsanitize sort created"

valg:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt

tester:
	cd push_swap_tester && bash basic_test.sh
