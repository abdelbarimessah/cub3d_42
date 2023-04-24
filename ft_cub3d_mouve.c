/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_mouve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:23:40 by amessah           #+#    #+#             */
/*   Updated: 2023/04/24 21:26:02 by amessah          ###   ########.fr       */
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

	double k = 0;
	while( k <= 1.2)
	{
		int x = map->px + 200 * cos(map->var + k);
		int y = map->py + 200 * sin(map->var + k);
		draw_line(map->mlx,map->win, map->px + 7, map->py + 7, x,y, 0xFFFFFF);
		k += 0.01;
	}
	// map->pa = (map->px * cos(map->var))  - (map->py * sin(map->var));
	// map->pb = (map->px * sin(map->var))  + (map->py * cos(map->var));
	// map->var = PI / 2;
	
	// int x = map->px + cos(map->var) * 180;
	// int y = map->py * sin(map->var) * 180 ;

	// printf(" map->var %lf\n", map->var);
	// int x = (cos(map->var ) * abs(map->px) ) - (sin(map->var ) * abs(map->py) );
	// int y = (sin(map->var ) * abs(map->px) ) + (cos(map->var) * abs(map->py) );
	// printf("%d %d %lf\n", x, y, map->var);

	// map->pa = ((cos(map->var) + sin(map->var)) * ( map->px - map->pa)) + map->px;
	// map->pb = ((cos(map->var) + sin(map->var)) * ( map->py - map->pb)) + map->py;
	
	// map->pa = ((map->pa - map->px) * cos(map->var) ) - ((map->pb - map->py) * sin(map->var)) + map->px;
	// map->pb = ((map->pa - map->px) * sin(map->var) ) + ((map->pb - map->py) * cos(map->var)) + map->py;
	// int i = 0;
	// while(i < 100)
	// {
	// 	draw_line(map->mlx, map->win, map->px + 7, map->py + 7, map->pa + i, map->pb, 0x000000);
	// 	i += 10;
	// }
	// draw_line(map->mlx,map->win, map->px + 7, map->py + 7, map->pa+ 60, map->pb + 60, 0xFFFFFF);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 200, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 300, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 400, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 500, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 600, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 700, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 800, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 900, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 1000, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 1100, map->pb, 0x000000);
	// draw_line(map->mlx, map->win, map->px + 7, map->py, map->pa + 1200, map->pb, 0x000000);
	
	// draw_line(map->mlx, map->win, map->px, map->py, -200, -100, 0x000000);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ptr, map->px, map->py);
	// draw_line(map->mlx, map->win, map->px, map->py, map->pa * 100, map->pb * 100, 0x000000);
 	return (1);
}