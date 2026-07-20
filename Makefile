# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/11 02:10:21 by pabartoc          #+#    #+#              #
#    Updated: 2026/07/20 18:48:59 by pabartoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Read the operating system (returns “Linux” or “Darwin” for macOS)
OS := $(shell uname -s)

# --- Compilers and Basic Flags ---
CC = cc
CFLAGS = -Wall -Wextra -Werror

# --- OS-specific configuration ---
ifeq ($(OS), Linux)
	# Einstellungen für Ubuntu / Linux
	MLX_DIR     = minilibx-linux
	MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
else
	# Einstellungen für macOS (Apple Silicon M-Chips)
	MLX_DIR     = minilibx_macos_metal
	MLX_FLAGS   = -L$(MLX_DIR) -lmlx -framework Metal -framework AppKit
endif

# Folder Structure
SRC_DIR     = src
INC_DIR     = inc
LIBFT_DIR   = libft

# The Library
LIBFT       = $(LIBFT_DIR)/libft.a

# Source Files and Object Files
SRCS        = $(SRC_DIR)/main.c \
			  $(SRC_DIR)/ft_atof.c \
			  $(SRC_DIR)/validation.c \

OBJS        = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Builds the actual `fractol` program
$(NAME): $(OBJ)
	@make -C $(MLX_DIR)
	@make -C libft
	$(CC) $(CFLAGS) $(OBJ) -Llibft -lft $(MLX_FLAGS) -o $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build libft by navigating to the libft folder and running ‘make’ there
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Deletes the generated .o files (including those in libft)
clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJS)

# Deletes the .o files AND the finished programs/libraries
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

# Phony prevents conflicts if there are files with the same names as our rules
.PHONY: all clean fclean re