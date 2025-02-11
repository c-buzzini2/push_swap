# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbuzzini <cbuzzini@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 12:59:11 by cbuzzini          #+#    #+#              #
#    Updated: 2025/02/11 13:14:07 by cbuzzini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HDR_FILES = push_swap.h
SRC_FILES = ft_split.c print.c utils_lists.c choose_cheapest.c push_swap.c \
			utils_split.c create_stack.c movements_ps.c movements_rot.c utils_strings.c \
			prepare_stacks.c sorting.c check_params.c

OBJ_FILES = $(SRC_FILES:.c=.o)

CC = cc 
FLAGS = -g -Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)

%.o: %.c $(HDR_FILES)

$(NAME): $(OBJ_FILES)
	$(CC) $(FLAGS) $(OBJ_FILES) -o $(NAME)

clean:
	rm -f $(OBJ_FILES) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all