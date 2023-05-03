/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_mouve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:23:40 by amessah           #+#    #+#             */
/*   Updated: 2023/05/02 02:28:16 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int render_rect(t_map *map, int x, int y,int height , int width, int color)
{
	int	i;
	int j;
	
	if (map->win == NULL)
		return (1);
	i = y;
	while (i < y + height)
	{
		j = x;
		while (j < x + width)
			mlx_pixel_put(map->mlx, map->win, j++, i, color);
		++i;
	}
	return (0);
}

void render_circle(t_map *map, int x, int y ,int r, int color)
{
	double angle = cos(1 - 1/r);
	int i = -1;
	int x1, y1;

	while(++i <= 360)
	{
		x1 = r * cos(i);
		y1 = r * sin(i);
		mlx_pixel_put(map->mlx, map->win, x + x1, y + y1, color);
	}
}
int	w_mouve(t_map *map)
{
	// draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	// if(map->str[map->px][map->py - 10] != '1')
	int a ;
	int b ;
	int c ;
	int d ;

	float var_b = ((map->py - 20) / 64) - floor((map->py - 10) / 64);
	if(var_b >= 0.5)
		b = floor((map->py  - 10)/ 64);
	else
		b =  ceil((map->py  - 10)/ 64);
	
	float var_a = (map->px / 64) - floor(map->px / 64);
	if(var_a >= 0.5)
		a = floor(map->px/ 64);
	else
		a =  ceil(map->px/ 64);

	float var_c = (map->px  + 10/ 64) - floor(map->px + 10/ 64);
	if(var_c >= 0.5)
		c = floor(map->px + 10/ 64);
	else
		c =  ceil(map->px + 10/ 64);
	
	float var_d = (map->px  - 10/ 64) - floor(map->px - 10/ 64);
	if(var_d >= 0.5)
		d = floor(map->px - 10/ 64);
	else
		d =  ceil(map->px - 10/ 64);
			
	// printf("w mouve %d %d %c\n", b,a, map->str[b][a]);
	
	if(map->str[b][a] != '1' && map->str[b][c] != '1' && map->str[b][d] != '1')
	{		
		// printf("%d %d\n", map->px, map->py);
		// print_rectangl_for_player(map, (map->px)  , (map->py - 10)  , WHITE);
		map->py -= 10;

		// int i = map->px;
		// int j = map->py;
		// int x = floor(map->px / 64);
		// int y = floor(map->py / 64);

		// while (i < 20)
		// {
		// 	j = 0;
		// 	while (j < 20)
		// 	{
		// 		map->img_addr[(int)((y + j) ) * 640 + (int)((x + i) )] = WHITE;
		// 		// conf->img.addr[(( (minimap * y) + (minimap * j)) * conf->player.width + (minimap * x) + (minimap * i))] = color;
		// 		j++;
		// 	}
		// 	i++;
		// }
	}

	
	
	// map_to_win(map);
	
	return (1);
}

int	s_mouve(t_map *map)
{
	// draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	int b = floor((map->py  + 5)/ 64);
	int a = floor(map->px / 64);
	int c = floor((map->px + 5) / 64);
	int d = floor((map->px - 5) / 64);
	// printf("s mouve %d %d %c\n", b,a, map->str[b][a]);
	
	if(map->str[b][a] != '1' && map->str[b][c] != '1' && map->str[b][d] != '1')
	{
		
		// printf("%d %d\n", map->px, map->py);
		// print_rectangl_for_player(map, (map->px) , (map->py + 10)  , WHITE);
		map->py += 5;
		// int i = map->px;
		// int j = map->py;
		// int x = floor(map->px / 64);
		// int y = floor(map->py / 64);

		// while (i < 20)
		// {
		// 	j = 0;
		// 	while (j < 20)
		// 	{
		// 		map->img_addr[(int)((y + j) ) * 640 + (int)((x + i) )] = WHITE;
		// 		// conf->img.addr[(( (minimap * y) + (minimap * j)) * conf->player.width + (minimap * x) + (minimap * i))] = color;
		// 		j++;
		// 	}
		// 	i++;
		// }
		
	}
	// map_to_win(map);
	return (1);
}




int	a_mouve(t_map *map)
{
	// draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	int b = floor(map->py/ 64);
	int a = floor((map->px - 5) / 64);
	int c = floor((map->py + 5) / 64);
	int d = floor((map->py - 5) / 64);
	//  printf("a mouve %d %d %c\n", b,a, map->str[b][a]);
	
	if(map->str[b][a] != '1' && map->str[c][a] != '1' && map->str[d][a] != '1')
	{	
		// printf("%d %d\n", map->px, map->py);
		// print_rectangl_for_player(map, (map->px - 10)  , (map->py)  , WHITE);
		map->px -= 5;
		// int i = map->px;
		// int j = map->py;
		// int x = floor(map->px / 64);
		// int y = floor(map->py / 64);

		// while (i < 20)
		// {
		// 	j = 0;
		// 	while (j < 20)
		// 	{
		// 		map->img_addr[(int)((y + j) ) * 640 + (int)((x + i) )] = WHITE;
		// 		// conf->img.addr[(( (minimap * y) + (minimap * j)) * conf->player.width + (minimap * x) + (minimap * i))] = color;
		// 		j++;
		// 	}
		// 	i++;
		// }
	}
	// map_to_win(map);
	return (1);
}

int	d_mouve(t_map *map)
{
	// draw_line(map->mlx, map->win, map->px + 3, map->py + 3, 150, 150, 0x00ff0000);
	int a = floor((map->px + 5) / 64);
	int b = floor(map->py/ 64);
	int c = floor((map->py + 5) / 64);
	int d = floor((map->py - 5) / 64);
	
	// printf("d mouve %d %d %c\n", b,a, map->str[b][a]);
	if(map->str[b][a] != '1' && map->str[c][a] != '1' && map->str[d][a] != '1')
	{	
		// printf("%d %d\n", map->px, map->py);
		// print_rectangl_for_player(map, (map->px + 10) / 64 , (map->py) / 64 , WHITE);
		map->px += 5;
		// int i = map->px;
		// int j = map->py;
		// int x = floor(map->px / 64);
		// int y = floor(map->py / 64);

		// while (i < 20)
		// {
		// 	j = 0;
		// 	while (j < 20)
		// 	{
		// 		map->img_addr[(int)((y + j) ) * 640 + (int)((x + i) )] = WHITE;
		// 		// conf->img.addr[(( (minimap * y) + (minimap * j)) * conf->player.width + (minimap * x) + (minimap * i))] = color;
		// 		j++;
		// 	}
		// 	i++;
		// }
	}
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
	map->var += 0.4;
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
	map->var -= 0.4;
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
	// print_rectangl_for_player(map, (int)map->px / 64, (int)map->py / 64, WHITE);

	int i = map->px;
	int j = map->py;
	int x = floor(map->px / 64);
	int y = floor(map->py / 64);


	// while (i < 20)
	// {
	// 	j = 0;
	// 	while (j < 20)
	// 	{
	// 		map->img_addr[(int)((y + j) ) * 640 + (int)((x + i) )] = WHITE;
	// 		// conf->img.addr[(( (minimap * y) + (minimap * j)) * conf->player.width + (minimap * x) + (minimap * i))] = color;
	// 		j++;
	// 	}
	// 	i++;
	// }

	
	// my_mlx_pixel_put(map, x,y, WHITE);
	// my_mlx_pixel_put(map, x+1,y, WHITE);
	// my_mlx_pixel_put(map, x,y +1, WHITE);
	// my_mlx_pixel_put(map, x+1,y+1, WHITE);
	// mlx_pixel_put(map->mlx, map->win, x , y + 1 , WHITE);
	// mlx_pixel_put(map->mlx, map->win, x  + 1, y , WHITE);
	// mlx_pixel_put(map->mlx, map->win, x , y , WHITE);
	// mlx_pixel_put(map->mlx, map->win, x  +1, y  +1, WHITE);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ptr, 0 , 0);

	// render_rect(map, map->px, map->py , 10 , 10 , WHITE);
	render_circle(map, map->px, map->py, 5, AQUA1);
	float distance = 600 / sin(PI /  3);
	 
	double k = 0;
	int io = 0;
	while( k <= (PI / 3) && io++ <= 360)
	{
		int x = map->px + 500 * cos(map->var + k);
		int y = map->py + 500 * sin(map->var + k);
		draw_line(map->mlx,map->win, map->px  + 1, map->py +1, x,y, 0xFF0000);
		k += 0.005;
	}
	// map->img_ptr = mlx_new_image(map->mlx, 1,1 );

	
	// mlx_put_image_to_window(map->mlx, map->win, map->img_ptr, map->px, map->py);
 	return (1);
}