# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 22:45:46 by aadnane           #+#    #+#              #
#    Updated: 2023/05/28 01:48:46 by aadnane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra -Ofast
# FLAGS = -Wall -Werror -Wextra
SRCS	=	mandatory/main.c \
		mandatory/parse/gnl.c \
		mandatory/parse/parsing.c \
		mandatory/parse/parse_utils.c \
		mandatory/parse/split.c \
		mandatory/parse/directions_paths.c \
		mandatory/parse/ceiling_and_floor.c \
		mandatory/parse/utils_floor_celling.c \
		mandatory/parse/parse_utils2.c \
		mandatory/parse/parse_utils3.c \
		mandatory/parse/parse_utils1.c \
		mandatory/parse/parse_utils4.c \
		mandatory/parse/aux_directions_traitement.c \
		mandatory/raycasting/ft_start_game.c \
		mandatory/raycasting/ft_cub3d_mouve.c \
		mandatory/raycasting/raycasting_utils.c \
		mandatory/raycasting/casting_rays.c \
		mandatory/raycasting/ft_init.c \
		mandatory/raycasting/ft_render.c \
		mandatory/raycasting/ft_utils.c \
		mandatory/raycasting/ft_key_mous.c \
		mandatory/raycasting/ft_horiz_verti.c \

SRCSB	= bonus/main_bonus.c \
		bonus/parse_bonus/gnl_bonus.c \
		bonus/parse_bonus/parsing_bonus.c \
		bonus/parse_bonus/parse_utils_bonus.c \
		bonus/parse_bonus/split_bonus.c \
		bonus/parse_bonus/directions_paths_bonus.c \
		bonus/parse_bonus/ceiling_and_floor_bonus.c \
		bonus/parse_bonus/utils_floor_celling_bonus.c \
		bonus/parse_bonus/parse_utils2_bonus.c \
		bonus/parse_bonus/parse_utils3_bonus.c \
		bonus/parse_bonus/parse_utils1_bonus.c \
		bonus/parse_bonus/parse_utils4_bonus.c \
		bonus/parse_bonus/aux_directions_traitement_bonus.c \
		bonus/raycasting_bonus/ft_start_game_bonus.c \
		bonus/raycasting_bonus/ft_cub3d_mouve_bonus.c \
		bonus/raycasting_bonus/raycasting_utils_bonus.c \
		bonus/raycasting_bonus/casting_rays_bonus.c \
		bonus/raycasting_bonus/ft_init_bonus.c \
		bonus/raycasting_bonus/ft_render_bonus.c \
		bonus/raycasting_bonus/ft_utils_bonus.c \
		bonus/raycasting_bonus/ft_key_mous_bonus.c \
		bonus/raycasting_bonus/ft_horiz_verti_bonus.c \

OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
NAME = cub3D
BONUS = cub3D_BONUS
HEADER = mandatory/parse/parse.h mandatory/raycasting/raycasting.h
HEADER_BS = parse_bonus/parse_bonus.h raycasting_bonus/raycasting_bonus.h



all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) minilibx/libmlx.a $(OBJS)  -lmlx -framework OpenGL -framework AppKit  -o $@

%.o  : %.c $(HEADER)
	$(CC) $(FLAGS) -Iminilibx -c $< -o $@

bonus : $(BONUS)

$(BONUS) : $(OBJSB)
	$(CC) minilibx/libmlx.a $(OBJSB)  -lmlx -framework OpenGL -framework AppKit  -o $@

%.o  : %.c $(HEADER_BS)
	$(CC) $(FLAGS) -Iminilibx -c $< -o $@

clean :
	rm -rf $(OBJS) $(OBJSB)

fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all