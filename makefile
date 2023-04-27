# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amessah <amessah@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/29 22:33:29 by amessah           #+#    #+#              #
#    Updated: 2023/04/26 18:16:54 by amessah          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror -Ofast

INCLUDE = cub3d.h

src = cub3d.c				\
	  ft_cub3d_outils.c		\
	  ft_cub3d_outils1.c	\
	  ft_cub3d_split.c		\
	  ft_start_game.c		\
	  ft_cub3d_mouve.c		\

OBJECTS = $(src:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(INCLUDES)
	$(CC)  $(OBJECTS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o : %.c
	$(CC)  -o $@ -c $<
	
clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME)

re: fclean all