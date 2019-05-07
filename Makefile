# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarpio- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/02 13:30:58 by jcarpio-          #+#    #+#              #
#    Updated: 2019/05/06 18:10:02 by jcarpio-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= fdf
SRC		:= main.c
OBJ		:= $(SRC:.c=.o)

CC		:= gcc
CFLAGS	:= -Wall -Wextra -Werror

## Libraries
LIBFT = libft/libft.a
LIBMLX = miniLibX/libmlx.a -framework OpenGL -framework AppKit
LIB = -I libft/ -I miniLibX/ $(LIBFT) $(LIBMLX)

all: $(NAME)

$(NAME): 
	$(CC) $(CFLAGS) $(FILES) $(LIB) $(SRC) -o $(NAME)

clean:
	rm -f $(NAME)

fclean: 
	rm -f $(NAME)

re: fclean all
