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

NAME	= minishell

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
LIBFLAGS	=
RM			= rm -rf

INCLUDE		= -Iinclude/
SRC_DIR		= src/
OBJ_DIR		= obj/
LIBFT_DIR	= libft/
LIBFT		= libft/libft.a


SRC_FILES	= 0_main.c \

SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ			= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

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
	@ echo "Compilating ${YELLOW}$(NAME) ${CLR_RMV}..."
	@ $(CC) $(CFLAGS) $(INCLUDE) $(SRC) -o $(NAME) $(LIBFLAGS) $(LIBFT)
	@ echo "${BLUE}           _       _     _          _ _"
	@ echo " _ __ ___ (_)_ __ (_)___| |__   ___| | |"
	@ echo "| '_ \` _ \\| | '_ \\| / __| '_ \\ / _ \\ | |"
	@ echo "| | | | | | | | | | \\__ \\ | | |  __/ | |"
	@ echo "|_| |_| |_|_|_| |_|_|___/_| |_|\\___|_|_|"
	@ echo "${R_BLUE}        by ${BLUE}daduarte ${R_BLUE}& ${BLUE}luibarbo"
	@ echo "${CLR_RMV}"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@ make clean -C $(LIBFT_DIR) -s
	@ $(RM) $(OBJ_DIR)
	@ echo "$(RED)Deleting $(CLR_RMV)object files"

fclean: clean
	@ make fclean -C $(LIBFT_DIR) -s
	@ $(RM) $(NAME)
	@ echo "$(RED)Deleting $(CLR_RMV)binary"

re: fclean all

.PHONY: all clean fclean re
