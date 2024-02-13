/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:15:26 by amessah           #+#    #+#             */
/*   Updated: 2023/05/28 02:20:11 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_bonus/parse_bonus.h"
#include "raycasting_bonus.h"

void	mlx_initialization(t_map *map)
{
	map->mlx = mlx_init();
	map->maxlinelenght = max_line_lenght(map->str);
	map->number_line = 0;
	while (map->str[map->number_line])
	map->number_line++;
	map->winh = WINDOW_HIGHT;
	map->winw = WINDOW_WIDTH;
	map->win = mlx_new_window(map->mlx, map->winw, map->winh, "cub3d");
}

void	init_player_direction(t_map *map)
{
	if (map->maze->player.player_direction == 1)
		map->player.rotationangle = PI / 2;
	else if (map->maze->player.player_direction == 2)
		map->player.rotationangle = 3 * PI / 2;
	else if (map->maze->player.player_direction == 3)
		map->player.rotationangle = 0;
	else if (map->maze->player.player_direction == 4)
		map->player.rotationangle = PI;
}

void	init_player_speed(t_map *map)
{
	if (map->number_line < 15)
	{
		map->player.movespeed = 2.0;
		map->player.rotationspeed = 1 * (PI / 180);
		map->mini_map_scale = 0.2;
	}
	else if (map->number_line > 40)
	{
		map->player.movespeed = 6.0;
		map->player.rotationspeed = 3 * (PI / 180);
		map->mini_map_scale = 0.1;
	}
	else
	{
		map->mini_map_scale = 0.2;
		map->player.movespeed = 3.0;
		map->player.rotationspeed = 1 * (PI / 180);
	}
}

void	init_map_texture(t_map *map)
{	
	char	*path[4];
	int		i;

	i = 0;
	map->texture = malloc(sizeof(map->texture) * 64);
	path[0] = map->maze->east_path;
	path[1] = map->maze->west_path;
	path[2] = map->maze->north_path;
	path[3] = map->maze->south_path;
	while (i < 4)
	{
		map->texture[i].height = TILE_SIZE;
		map->texture[i].width = TILE_SIZE;
		map->texture[i].image_ptr = \
			mlx_xpm_file_to_image(map->mlx, path[i], \
			&map->texture[i].width, &map->texture[i].width);
		if (!map->texture[i].image_ptr)
			ft_error ("xpm image ");
		map->texture[i].image_addr = \
			(int *)mlx_get_data_addr(map->texture[i].image_ptr, \
			&map->texture[i].bits_per_pixel, \
			&map->texture[i].size_line, &map->texture[i].endian);
		i++;
	}
}

void	init_player_data(t_map *map)
{
	map->count = 0;
	map->player.raduis = 2;
	map->player.turndirection = 0;
	map->player.walkdirection = 0;
	map->player.walk_a = 0;
	map->player.walk_d = 0;
	map->player.walk_s = 0;
	map->player.walk_w = 0;
	init_player_direction(map);
	init_player_speed(map);
	init_map_texture(map);
	get_player_position(map);
	map->num_rays = map->winw / WALL_STRIP_WIDTH;
	map->rays = malloc(sizeof(t_rays) * map->num_rays);
}
