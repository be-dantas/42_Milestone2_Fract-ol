# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 10:45:53 by bedantas          #+#    #+#              #
#    Updated: 2025/10/16 11:51:50 by bedantas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME            = fractol
CC              = cc
CFLAGS          = -Wall -Wextra -Werror
MLX_FLAGS       = -O3 -lXext -lX11 -lm -lz

LIBFT_DIR       = ./libft
MLX_DIR         = ./minilibx-linux

LIBFT_LIB       = $(LIBFT_DIR)/libft.a
MLX_LIB         = $(MLX_DIR)/libmlx_Linux.a

SRCS =	fractol.c			\
		fractol_utils.c		\
		valid_inputs.c		\
		mand_and_julia.c	\
		mouse_key.c

OBJS = $(SRCS:.c=.o)

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

RESET   = \033[0m
GREEN   = \033[1;32m
YELLOW  = \033[1;33m
BLUE    = \033[1;34m
RED     = \033[1;31m

# Prefixo para comandos silenciosos
SILENT = @

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: header $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(GREEN)[OK]$(RESET) Linking $(NAME)"
	$(SILENT)$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

$(LIBFT_LIB):
	@echo "$(YELLOW)[LIBFT]$(RESET) Compilando Libft..."
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) > /dev/null

$(MLX_LIB):
	@echo "$(YELLOW)[MLX]$(RESET) Compilando MiniLibX..."
	$(SILENT)$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

%.o: %.c
	@echo "$(GREEN)[CC]$(RESET) $<"
	$(SILENT)$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(RED)[CLEAN]$(RESET) Removendo objetos..."
	$(SILENT)rm -f $(OBJS)
	$(SILENT)$(MAKE) clean -C $(LIBFT_DIR) > /dev/null
	$(SILENT)$(MAKE) clean -C $(MLX_DIR) > /dev/null

fclean: clean
	@echo "$(RED)[FCLEAN]$(RESET) Removendo binário..."
	$(SILENT)rm -f $(NAME)
	$(SILENT)$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null

re: fclean all

.PHONY: all clean fclean re header
