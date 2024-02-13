/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_mous.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:50:35 by amessah           #+#    #+#             */
/*   Updated: 2023/05/28 02:16:46 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"
#include "../parse/parse.h"

int	keypressed(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	mlx_clear_window(map->mlx, map->win);
	if (key == KEY_W)
		map->player.walk_w = 1;
	if (key == KEY_S)
		map->player.walk_s = 1;
	if (key == KEY_A)
		map->player.walk_a = 1;
	if (key == KEY_D)
		map->player.walk_d = 1;
	if (key == KEY_RIGHT)
		map->player.turndirection = +1;
	if (key == KEY_LEFT)
		map->player.turndirection = -1;
	if (key == KEY_ESC)
	{
		write(1, "game over !\n", 13);
		exit(0);
	}
	map_to_win(map);
	return (1);
}

int	keyreleased(int key, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	mlx_clear_window(map->mlx, map->win);
	if (key == KEY_W)
		map->player.walk_w = 0;
	if (key == KEY_S)
		map->player.walk_s = 0;
	if (key == KEY_A)
		map->player.walk_a = 0;
	if (key == KEY_D)
		map->player.walk_d = 0;
	if (key == KEY_RIGHT)
		map->player.turndirection = 0;
	if (key == KEY_LEFT)
		map->player.turndirection = 0;
	if (key == KEY_ESC)
	{
		write(1, "game over !\n", 13);
		exit(0);
	}
	map_to_win(map);
	return (1);
}

int	mouse_movement(int x, int y, void *param)
{
	t_map	*map;

	map = (t_map *)param;
	mlx_mouse_hide();
	mlx_clear_window(map->mlx, map->win);
	if (y <= map->winh && y >= 0)
	{
		if (x <= map->winw && x >= 0)
		{
			if (x > map->winw / 2)
				map->player.turndirection = 1;
			else if (x < map->winw / 2)
				map->player.turndirection = -1;
		}
	}
	mlx_mouse_move(map->win, WINDOW_WIDTH / 2, WINDOW_HIGHT / 2);
	map_to_win(map);
	map->player.turndirection = 0;
	return (0);
}
