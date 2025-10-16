# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedantas <bedantas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/16 10:45:53 by bedantas          #+#    #+#              #
#    Updated: 2025/10/16 13:32:05 by bedantas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                   SETTINGS                                   #
# **************************************************************************** #

NAME		= fractol
BONUS_NAME	= fractol_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
MLX_FLAGS	= -O3 -lXext -lX11 -lm -lz

LIBFT_DIR	= ./libft
MLX_DIR		= ./minilibx-linux

LIBFT_LIB	= $(LIBFT_DIR)/libft.a
MLX_LIB		= $(MLX_DIR)/libmlx_Linux.a

SRCS =	fractol.c			\
		fractol_utils.c		\
		valid_inputs.c		\
		mand_and_julia.c	\
		mouse_key.c

BONUS_SRCS	= $(wildcard bonus/*_bonus.c)

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

INCLUDES	= -I. -I$(LIBFT_DIR)

# **************************************************************************** #
#                                   COLORS                                     #
# **************************************************************************** #

RESET		= \033[0m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RED			= \033[1;31m

SILENT = @

# **************************************************************************** #
#                                   RULES                                      #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(GREEN)[OK]$(RESET) Linking $(NAME)"
	$(SILENT)$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_LIB) $(MLX_LIB)
	@echo "$(GREEN)[OK]$(RESET) Linking $(BONUS_NAME)"
	$(SILENT)$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT_LIB) $(MLX_LIB) $(MLX_FLAGS) -o $(BONUS_NAME)

$(LIBFT_LIB):
	@echo "$(YELLOW)[LIBFT]$(RESET) Compilando Libft..."
	$(SILENT)$(MAKE) -C $(LIBFT_DIR) > /dev/null 2>&1

$(MLX_LIB):
	@echo "$(YELLOW)[MLX]$(RESET) Compilando MiniLibX..."
	$(SILENT)$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

%.o: %.c
	@echo "$(GREEN)[CC]$(RESET) $<"
	$(SILENT)$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# **************************************************************************** #
#                                   CLEANING                                   #
# **************************************************************************** #

clean:
	@echo "$(RED)[CLEAN]$(RESET) Removendo objetos..."
	$(SILENT)rm -f $(OBJS) $(BONUS_OBJS)
	$(SILENT)$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	$(SILENT)$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1

fclean: clean
	@echo "$(RED)[FCLEAN]$(RESET) Removendo binários..."
	$(SILENT)rm -f $(NAME) $(BONUS_NAME)
	$(SILENT)$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1

re: fclean all

.PHONY: all bonus clean fclean re
