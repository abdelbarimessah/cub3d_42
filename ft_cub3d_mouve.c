/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_mouve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:23:40 by amessah           #+#    #+#             */
/*   Updated: 2023/04/26 21:29:15 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	w_mouve(t_map *map)
{
	// draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	map->py -= 20;
	// map_to_win(map);
	
	return (1);
}

int	s_mouve(t_map *map)
{
	// draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	map->py += 20;
	// map_to_win(map);
	return (1);
}

int	a_mouve(t_map *map)
{
	// draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	map->px -= 20;
	// map_to_win(map);
	return (1);
}

int	d_mouve(t_map *map)
{
	// draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	map->px += 20;
	// map_to_win(map);
	return (1);
}

void	key_right_m(t_map *map)
{
	// printf("r1 - %lf %d %d\n", map->var, map->pa, map->pb);
	// map->var -= 0.1;
	// if(map->var < 0)
	// 	map->var += PI * 2;
	// map->pa = cos(map->var) * map->var; 
	// map->pb = sin(map->var) * map->var;
	// printf("r2 - %lf %d %d\n", map->var, map->pa, map->pb);
	// map_to_win(map);
	// map->pa += 10;
	// map->pb += 10;
	map->var += 0.1;
}

void	key_left_m(t_map *map)
{
	// printf("l1 - %lf %d %d\n", map->var, map->pa, map->pb);
	// map->var += 0.1;
	// if(map->var > 2 * PI)
	// 	map->var -= PI * 2;
	// map->pa = cos(map->var) * map->var; 
	// map->pb = sin(map->var) * map->var;
	// printf("l2 - %lf %d %d\n", map->var, map->pa, map->pb);
	// map_to_win(map);
	// map->pa -= 10;
	// map->pb += 10;
	// printf("%d\n", map->pa);
	map->var -= 0.1;
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
		write(1, "game over !\n", 14);
		ft_free(map->str);
		exit(0);
	}
	map_to_win(map);
	// printf("%lf\n" ,map->var);
	// int z = map->px + 200 * cos(map->var + 1.57);
	// int w = map->py + 200 * sin(map->var + 1.57);

	// draw_line(map->mlx,map->win, map->px + 7, map->py + 7, z, w, 0xFFFFFF);

	mlx_put_image_to_window(map->mlx, map->win, map->img_ptr, 0 , 0);

	float distance = 600 / sin(PI /  3);
	 
	double k = 0;
	while( k <= (PI / 3))
	{
		int x = map->px + 600 * cos(map->var + k);
		int y = map->py + 600 * sin(map->var + k);
		draw_line(map->mlx,map->win, map->px  + 3, map->py , x,y, 0xFF0000);
		k += 0.005;
	}
	// map->img_ptr = mlx_new_image(map->mlx, 1,1 );

	
	// mlx_put_image_to_window(map->mlx, map->win, map->img_ptr, map->px, map->py);
 	return (1);
}