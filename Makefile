# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/04 11:01:48 by luibarbo          #+#    #+#              #
#    Updated: 2024/12/04 11:04:12 by luibarbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================ #
#	GENERAL                                                                    #
# ============================================================================ #

NAME	= cub3d

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
LIBFLAGS	= -L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lbsd -lXext -lX11 -lm
RM			= rm -rf

INCLUDE		= -Iinclude/
SRC_DIR		= src/
OBJ_DIR		= obj/
LIBFT_DIR	= libft/
LIBFT		= libft/libft.a
MLX_DIR		= minilibx-linux/
MLX_LIB		= $(MLX_DIR)/libmlx_linux.a


SRC_FILES	= main.c error.c \
			  0_init/0_init_data.c 0_init/0_init_mlx.c 0_init/0_init_textures.c \
			  1_parsing/1_parse_file.c 1_parsing/1_valid_arg.c

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_FILES	= $(SRC_FILES:.c=.o)

OBJ			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# ============================================================================ #
#	COLORS                                                                     #
# ============================================================================ #

CLR_RMV	= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
R_GREEN	= \033[0;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
R_BLUE	= \033[0;34m
CYAN 	= \033[1;36m

# ============================================================================ #
#	RULES                                                                      #
# ============================================================================ #

all: $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ)
	@ make -C $(LIBFT_DIR) -s
	@ make -C $(MLX_DIR) -s
	@ echo "Compilating ${YELLOW}$(NAME) ${CLR_RMV}..."
	@ $(CC) $(CFLAGS) $(INCLUDE) $(SRC) -o $(NAME) $(LIBFLAGS) $(LIBFT)
	@ echo " "
	@ echo "${BLUE}                     █████      ████████      █████"
	@ echo "                    ░░███      ███░░░░███    ░░███ "
	@ echo "  ██████  █████ ████ ░███████ ░░░    ░███  ███████ "
	@ echo " ███░░███░░███ ░███  ░███░░███   ██████░  ███░░███ "
	@ echo "░███ ░░░  ░███ ░███  ░███ ░███  ░░░░░░███░███ ░███ "
	@ echo "░███  ███ ░███ ░███  ░███ ░███ ███   ░███░███ ░███ "
	@ echo "░░██████  ░░████████ ████████ ░░████████ ░░████████ "
	@ echo " ░░░░░░    ░░░░░░░░ ░░░░░░░░   ░░░░░░░░   ░░░░░░░░ "
	@ echo " "
	@ echo "${R_BLUE}              by ${BLUE}daduarte ${R_BLUE}& ${BLUE}luibarbo"
	@ echo "${CLR_RMV}"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/0_init

# @mkdir -p $(OBJ_DIR)/1_parsing
# @mkdir -p $(OBJ_DIR)/2_movement
# @mkdir -p $(OBJ_DIR)/3_render
# @mkdir -p $(OBJ_DIR)/4_exit

clean:
	@ make clean -C $(LIBFT_DIR) -s
	@ make clean -C $(MLX_DIR) -s
	@ $(RM) $(OBJ_DIR)
	@ echo "$(RED)Deleting $(CLR_RMV)object files"

fclean: clean
	@ make fclean -C $(LIBFT_DIR) -s
	@ $(RM) $(NAME)
	@ echo "$(RED)Deleting $(CLR_RMV)binary"

re: fclean all

.PHONY: all clean fclean re
