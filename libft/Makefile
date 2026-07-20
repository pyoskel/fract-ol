# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabartoc <pabartoc@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/08 22:11:45 by pabartoc          #+#    #+#              #
#    Updated: 2026/05/30 00:12:55 by pabartoc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libft.a

CC      = cc
CFLAGS  = -Wall -Wextra -Werror -I $(INC_DIR)
AR = ar rcs
RM = rm -f

# ---------------------------------------------------------
# ORDNER-STRUKTUR
# ---------------------------------------------------------
SRC_DIR = src
INC_DIR = inc
OBJ_DIR = obj

# ---------------------------------------------------------
# DATEIEN (Nur die Namen, OHNE Pfad)
# ---------------------------------------------------------
FILES = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c

# ---------------------------------------------------------
# PFADE AUTOMATISCH GENERIEREN
# ---------------------------------------------------------
# Setzt vor jeden Dateinamen "src/" (z.B. src/ft_atoi.c)
SRC = $(addprefix $(SRC_DIR)/, $(FILES))

# Macht aus .c ein .o und setzt "obj/" davor (z.B. obj/ft_atoi.o)
OBJ = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))

# ---------------------------------------------------------
# REGELN
# ---------------------------------------------------------
all: $(NAME)

# Bibliothek erstellen
$(NAME): $(OBJ)
	@$(AR) $(NAME) $(OBJ)
	
# Kompilierungs-Regel
# $< ist die .c Datei, $@ ist die .o Datei
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Object files aufräumen
clean:
	@$(RM) -r $(OBJ_DIR)

# Alles restlos aufräumen
fclean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(NAME)

# Alles neu bauen
re: fclean all

.PHONY: all clean fclean re