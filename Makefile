# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smortier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/24 23:18:45 by smortier          #+#    #+#              #
#    Updated: 2018/01/24 23:27:26 by smortier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf

SRC_NAME	=	main.c \
				get_next_line.c \
				init_drawing.c \
				fill_params.c  \
				find_in_lst.c \
				ft_put_pixel.c \
				key_holder.c \
				bresenham.c \
				ft_draw_image.c \
				reset_tab.c \
				color.c \
				where_m_i.c \

OBJ_NAME	=	$(SRC:.c=.o)
SRC_PATH	=	.
OBJ_PATH	=	.
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra
CPPFLAGS	=	-I.

LDLIBS		=	-lft
LDFLAGS		=	-Llibft

FLAGS1 = -framework OpenGL -framework AppKit

MLX = minilibx

# PROGRESS BAR
T = $(words $(OBJ))
N = 0
C = $(words $N)$(eval N := x $N)
ECHO = "[`expr $C  '*' 100 / $T`%]"

#Colors
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(NAME)

$(NAME): $(OBJ) MLX
	@$(MAKE) -s -C libft
	@$(CC) $(LDFLAGS) $(FLAGS1) $(LDLIBS) $(OBJ) -o $(NAME) -L./minilibx -lmlx
	@printf "\n"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) -c $^
	@printf "%-60b\r" "$(ECHO) $(_GREEN) Compiling $@ $(_END)"

MLX : $(MLX)
	@make -s -C $(MLX)/

clean:
	@$(MAKE) clean -C libft
	@$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all
