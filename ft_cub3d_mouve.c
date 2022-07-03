/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_mouve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:23:40 by amessah           #+#    #+#             */
/*   Updated: 2022/07/03 04:04:56 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	w_mouve(t_map *map)
{
	draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	map->py -= 20;
	// map_to_win(map);
	
	return (1);
}

int	s_mouve(t_map *map)
{
	draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	map->py += 20;
	// map_to_win(map);
	return (1);
}

int	a_mouve(t_map *map)
{
	draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	map->px -= 20;
	// map_to_win(map);
	return (1);
}

int	d_mouve(t_map *map)
{
	draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	map->px += 20;
	// map_to_win(map);
	return (1);
}

void	key_right_m(t_map *map)
{
	map->pa -= 0.1;
	if(map->pa < 0)
		map->pa += PI * 2;
	map->px = cos(map->pa) * 5; 
	map->py = sin(map->pa) * 5;
	map_to_win(map);
}

void	key_left_m(t_map *map)
{
	map->pa += 0.1;
	if(map->pa > 2 * PI)
		map->pa -= PI * 2;
	map->px = cos(map->pa) * 5; 
	map->py = sin(map->pa) * 5;
	map_to_win(map);
}

int	mouvement(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	mlx_clear_window(map->mlx, map->win);
	if (key == KEY_W)
		w_mouve(map);
	if (key == KEY_S)
		s_mouve(map);
	if (key == KEY_A)
		a_mouve(map);
	if (key == KEY_D)
		d_mouve(map);
	if(key == KEY_RIGHT)
		key_right_m(map);
	if(key == KEY_LEFT)
		key_left_m(map);
	if (key == KEY_ESC)
	{
		write(1, "\ngame over !\n", 14);
		ft_free(map->str);
		exit(0);
	}
	map_to_win(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ptr, map->px, map->py);
	return (1);
}