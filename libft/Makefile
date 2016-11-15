# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fhenry <fhenry@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/16 06:45:34 by fhenry            #+#    #+#              #
#    Updated: 2016/11/08 10:37:32 by fhenry           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME	 = 	libft.a

CC		 = 	gcc
CFLAGS	 = 	-Wall -Werror -Wextra -g

SRC_PATH =	src/
OBJ_PATH =	obj/
INC_PATH = 	include/

SRC_NAME =	add_c_to_string.c \
			buff_string.c \
			del_c_to_string.c \
			fill_with_c.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_fill_wstring.c \
			ft_free_tab.c \
			ft_get_bytes.c \
			ft_is_c_size.c \
			ft_is_lower.c \
			ft_is_upper.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_islower.c \
			ft_isoption.c \
			ft_isprecision.c \
			ft_isprint.c \
			ft_istype.c \
			ft_itoa.c \
			ft_itoa_base.c \
			ft_lstadd.c \
			ft_lstdel.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_base.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_str_captalizer.c \
			ft_str_printable.c \
			ft_strcat.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strcpy_printf.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strjoin_free.c \
			ft_strjoin_printf.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strlen_printf.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnlen.c \
			ft_strnncpy.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strrev.c \
			ft_strsplit.c \
			ft_strsrch.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_ull_itoa_base.c \
			ft_wstrlen.c \
			get_next_line.c \
			get_sign.c \
			get_struct_part1.c \
			get_struct_part2.c \
			init_struct.c \
			len_arg_max.c \
			preci_max.c \
			printf.c \
			type_c.c \
			type_di.c \
			type_oux.c \
			type_p.c \
			type_s.c \
			width_max.c \
			expand_tab_c.c

OBJ_NAME = 	$(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) $(CFLAGS) -I $(INC_PATH) -c $< -o $@

clean:
		@rm -rf $(OBJ_PATH)

fclean: clean
		@rm -f $(NAME)

re: fclean all
