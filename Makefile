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
SRC_PATH	=	./src
OBJ_PATH	=	.
SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

CC			=	clang
CFLAGS		=	-Wall -Werror -Wextra
CPPFLAGS	=	-I./includes

LDLIBS		=	-lft
LDFLAGS		=	-Llibft

FLAGS1 = -framework OpenGL -framework AppKit

MLX = minilibx

all: $(NAME)

$(NAME): $(OBJ) MLX
	@$(MAKE) -s -C libft
	@$(CC) $(LDFLAGS) $(FLAGS1) $(LDLIBS) $(OBJ) -o $(NAME) -L./minilibx -lmlx

MLX : $(MLX)
	@make -s -C $(MLX)/

clean:
	@$(MAKE) clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, fclean, re, all
