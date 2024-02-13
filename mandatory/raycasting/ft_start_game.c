/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:53:11 by amessah           #+#    #+#             */
/*   Updated: 2023/05/28 02:06:16 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"
#include "raycasting.h"

void	get_player_position(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->str[i])
	{
		j = 0;
		while (map->str[i][j])
		{
			if (map->str[i][j] == 'N' || map->str[i][j] == 'W'
				|| map->str[i][j] == 'E' || map->str[i][j] == 'S')
			{
				map->px = j * TILE_SIZE + (TILE_SIZE / 2);
				map->py = i * TILE_SIZE + (TILE_SIZE / 2);
			}
			j++;
		}
		i++;
	}
}

int	map_to_win(t_map *map)
{
	initialize_img_data(map);
	if (map->count != 0)
		render_3d_walls(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ptr, 0, 0);
	mlx_destroy_image(map->mlx, map->img_ptr);
	map->player.rotationangle += map->player.turndirection * \
		map->player.rotationspeed;
	map->player.rotationangle = normlize(map->player.rotationangle);
	update_player_place(map);
	rays(map);
	return (0);
}

void	cub3d_game(t_map *map)
{
	mlx_initialization(map);
	init_player_data(map);
	mlx_hook(map->win, 2, 0, &keypressed, map);
	mlx_hook(map->win, 3, 0, &keyreleased, map);
	mlx_hook(map->win, 6, 0, &mouse_movement, map);
	mlx_loop_hook(map->mlx, &map_to_win, map);
	free(map->rays);
	mlx_loop(map->mlx);
}
