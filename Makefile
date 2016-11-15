# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/05 14:51:08 by fhenry            #+#    #+#              #
#    Updated: 2016/11/12 14:59:11 by fhenry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re test

NAME = lem-in

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_PATH = src/
OBJ_PATH = obj/
LIB_PATH = libft/
INC_PATH = includes/

SRC_NAME = main.c \
		   init_env.c \
		   parsing.c \
		   str_is_digit.c \
		   len_param.c \
		   error_parsing.c \
		   pathfinding.c \
		   print_lemin.c \
		   print_map.c \
		   free_lemin.c \
		   find_distance.c \
		   expand_tab_i.c \
		   lex_ant.c \
		   parse_room.c \
		   parse_pipe.c \
		   secure_pipe.c \
		   save_line.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIB_PATH)
	@$(CC) -o $(NAME) $(OBJ) -I $(INC_PATH) $(LIB_PATH)libft.a

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@$(MAKE) -C $(LIB_PATH) $@

fclean: clean
	@rm -f $(NAME)
	@rm -f test
	@$(MAKE) -C $(LIB_PATH) $@

test: all
	@$(CC) -o test main_test.c -I $(INC_PATH) $(LIB_PATH)libft.a

re: fclean all
