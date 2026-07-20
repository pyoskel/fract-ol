# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/07/11 02:10:21 by pabartoc          #+#    #+#              #
#    Updated: 2026/07/20 23:43:07 by pabartoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Read the operating system (returns “Linux” or “Darwin” for macOS)
OS := $(shell uname -s)

# --- Compilers and Basic Flags ---
CC = cc
CFLAGS = -Wall -Wextra -Werror

# --- OS-specific configuration ---
# Settings for Ubuntu / Linux
ifeq ($(OS), Linux)
	MLX_DIR     = minilibx-linux
	MLX_FLAGS   = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
# In Linux, we don't need a copy command
	MLX_EXEC    =
# Settings for macOS (Apple Silicon M-series chips)
else
	MLX_DIR     = minilibx_macos_metal
	MLX_FLAGS   = -L$(MLX_DIR) -lmlx -framework Metal -framework AppKit
# On macOS, we copy the dylib to the root directory
	MLX_EXEC    = cp $(MLX_DIR)/libmlx.dylib .
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
			  $(SRC_DIR)/validation.c

OBJS        = $(SRCS:.c=.o)

# Default rule
all: $(NAME)

# Builds the actual `fractol` program
$(NAME): $(OBJS)
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@make -C libft
	$(CC) $(CFLAGS) $(OBJS) -Llibft -lft $(MLX_FLAGS) -o $(NAME)
	$(MLX_EXEC)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -I$(LIBFT_DIR)/inc -c $< -o $@

# Build libft by navigating to the libft folder and running ‘make’ there
$(LIBFT):
	@make -C $(LIBFT_DIR)

# Deletes the generated .o files (including those in libft)
clean:
	@make -C $(LIBFT_DIR) clean
	@make -C $(MLX_DIR) clean
	@rm -f $(OBJS)

# Deletes the .o files AND the finished programs/libraries
fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@rm -f libmlx.dylib

# Rebuild everything
re: fclean all

# Phony prevents conflicts if there are files with the same names as our rules
.PHONY: all clean fclean re