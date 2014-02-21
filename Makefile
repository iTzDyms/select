#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cheron <cheron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 17:06:50 by cheron            #+#    #+#              #
#    Updated: 2014/02/21 17:33:46 by cheron           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = gcc
CFLAGS = -Wall -Werror -Wextra
OFLAGS = -03
RM = @rm -rf

LIBFT_DIR = ./libft

INCLUDES_DIR = ./libft/includes

LIBFT = $(LIBFT_DIR)/libft.a

NAME = ft_select

OBJ_DIR = obj
SRC_DIR = srcs

SRC = 	main.c \
		ft_clstadd.c \
		ft_clstnew.c \
		ft_create_clst.c \
		ft_proceed_input.c \
		ft_print_res.c \
		ft_get_input.c \
		ft_clst_del.c \
		ft_putclst.c \
		ft_resize.c \
		ft_sig.c \
		ft_term.c \

OBJ = $(SRC:.c=.o)
POBJ = $(addprefix $(OBJ_DIR)/, $(OBJ))

LIBTERM_DIR = /usr/include/
LIBTERM = -ltermcap

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(LIBFT):
	@echo "\nCompilation of objects for "$(LIBFT)
	@($(MAKE) -C $(LIBFT_DIR))

$(NAME): $(POBJ) $(LIBFT)
	@echo "\nLinking "$(NAME)""
	@$(CC) $(CFLAGS) $(OFLAGS) -o $(NAME) $^ \
	-L$(LIBFT_DIR) -lft -L$(LIBTERM_DIR) $(LIBTERM) \
	-I$(INCLUDES_DIR)
	@echo "\n\x1b[32;01mdone!\x1b[0m"

clean:
	@echo "\nCleaning OBJ"
	$(RM) $(POBJ)

fclean: clean
	@echo "\nCleaning "$(NAME)""
	$(RM) $(NAME)
	@($(MAKE) $@ -C $(LIBFT_DIR))

re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INCLUDES_DIR)
	@$(CC) $(CFLAGS) $(OFLAGS) -c $< -o $@ -I $(INCLUDES_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

.PHONY: all clean re fclean
