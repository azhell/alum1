# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ishyian <ishyian@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/30 14:57:31 by ishyian           #+#    #+#              #
#    Updated: 2019/07/20 18:19:14 by ishyian          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =				gcc
NAME =				alum1
CFLAGS =			-Wall -Wextra -g
SRCS =				./src/$(NAME).c \
					./src/global.c \
					./src/usage.c \
					./src/read_map.c \
					./src/run_game.c \
					./src/ai.c \

OBJ =				$(SRCS:.c=.o)
LIBS = 				-lft
LIB_DIR =			./libft/
LIB_FT =			./libft/libft.a
INCLUDES =			./inc/$(NAME).h

.SILENT:

all: 				$(NAME)

$(NAME):			$(LIB_FT) $(OBJ)
					$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBS) -L $(LIB_DIR)

$(OBJ): 			%.o: %.c $(INCLUDES)
					$(CC) $(CFLAGS) -I $(INCLUDES) -o $@ -c $<

$(LIB_FT):			libft
					make -C $(LIB_DIR)

libft:
					make -C $(LIB_DIR)

clean:
					rm -f $(OBJ)
					make clean -C $(LIB_DIR)

fclean: 			clean
					rm -f $(NAME)
					make fclean -C $(LIB_DIR)

re: 				fclean all

.PHONY: 			all libft clean fclean
