/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:20:06 by amessah           #+#    #+#             */
/*   Updated: 2023/05/28 02:06:22 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"
#include "raycasting.h"

void	number_texture(t_map *map, int i)
{
	if (!map->rays[i].foundvwh
		&& (map->rays[i].rayangle >= 0 && map->rays[i].rayangle < PI))
		map->texture_nb = 2;
	else if (!map->rays[i].foundvwh
		&& (map->rays[i].rayangle < 2 * M_PI && map->rays[i].rayangle >= PI))
		map->texture_nb = 3;
	if (map->rays[i].foundvwh
		&& (map->rays[i].rayangle >= (PI / 2)
			&& map->rays[i].rayangle < (1.5 * PI)))
		map->texture_nb = 0;
	else if (map->rays[i].foundvwh
		&& (((map->rays[i].rayangle <= (PI / 2)
					&& map->rays[i].rayangle >= 0))
			|| (map->rays[i].rayangle > (1.5 * PI)
				&& map->rays[i].rayangle) < 2 * M_PI))
		map->texture_nb = 1;
}

void	render_walls_floor(t_map *map)
{
	int	disfromtop;

	while (map->render.j < map->render.wall_bot_pix)
	{
		disfromtop = map->render.j
			+(map->render.wallstripheight / 2) - (map->winh / 2);
		map->render.textureoffsety = disfromtop
			* ((float)TILE_SIZE / map->render.wallstripheight);
		map->render.color = \
			map->texture[map->texture_nb].image_addr[(TILE_SIZE * \
				map->render.textureoffsety)
			+ (int)map->render.textureoffsetx];
		map->img_addr[((int)map->render.j * \
			(map->winw)) + (int)map->render.i] = map->render.color;
		map->render.j++;
	}
	while (map->render.j < map->winh)
	{
		map->img_addr[(int)((map->render.j))
			*(map->winw) + (int)((map->render.i))] = \
				create_rgb(map->maze->floor_color[0], \
				map->maze->floor_color[1], map->maze->floor_color[2]);
		map->render.j++;
	}
}

void	render_ceil(t_map *map)
{
	map->render.wall_bot_pix = 0;
	map->render.wall_top_pix = 0;
	map->render.ray_distance = map->rays[map->render.i].distance * \
		cos(map->rays[map->render.i].rayangle - map->player.rotationangle);
	map->render.wallstripheight = (TILE_SIZE / map->render.ray_distance) * \
		map->render.distance_plane;
	map->render.wall_top_pix = (map->winh / 2) - \
		(map->render.wallstripheight / 2);
	if (map->render.wall_top_pix < 0)
		map->render.wall_top_pix = 0;
	map->render.wall_bot_pix = (map->winh / 2) + \
		(map->render.wallstripheight / 2);
	if (map->render.wall_bot_pix > map->winh)
		map->render.wall_bot_pix = map->winh;
	map->render.j = 0;
	while (map->render.j < map->render.wall_top_pix)
	{
		map->img_addr[map->render.j * (map->winw) + map->render.i] = \
			create_rgb(map->maze->ceiling_color[0], \
			map->maze->ceiling_color[1], map->maze->ceiling_color[2]);
		map->render.j++;
	}
}

void	render_3d_walls(t_map *map)
{	
	map->render.i = 0;
	map->render.j = 0;
	map->render.distance_plane = (map->winw / 2) / \
		tan((FOV_ANGLE * (PI / 180)) / 2);
	while (map->render.i < map->num_rays)
	{
		render_ceil(map);
		if (map->rays[map->render.i].foundvwh)
			map->render.textureoffsetx = \
				(int)map->rays[map->render.i].hity % TILE_SIZE;
		else
			map->render.textureoffsetx = \
				(int)map->rays[map->render.i].hitx % TILE_SIZE;
		map->render.j = map->render.wall_top_pix;
		number_texture(map, map->render.i);
		render_walls_floor(map);
		map->render.i++;
	}
}

void	initialize_img_data(t_map *map)
{	
	int		k;

	k = map->winw / TILE_SIZE;
	map->img_ptr = mlx_new_image(map->mlx, map->winw, map->winh);
	map->img_addr = (int *)mlx_get_data_addr(map->img_ptr, \
		&map->bits_per_pixel, &k, &map->endian);
}
