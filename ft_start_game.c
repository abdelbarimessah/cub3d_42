/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:53:11 by amessah           #+#    #+#             */
/*   Updated: 2022/07/03 03:51:32 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_map *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw(t_map *map, int i, int j)
{
	if (map->str[i][j] == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall,
			j * map->img_w, i * map->img_h);
	else
		mlx_put_image_to_window(map->mlx, map->win, map->empty,
			j * map->img_w, i * map->img_h);
}

void	draw_player(t_map *map)
{
	int i = 0;
	int j = 0;
	
	map->img_ptr = mlx_new_image(map->mlx, 17, 17);
	map->img_addr = mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel, &map->size_line, &map->endian);
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			my_mlx_pixel_put(map, i, j, 0x00ff0000);
			j++;
		}
		i++;
	}
}

void    map_to_win(t_map *map)
{
	int i;
	int j;

	i = -1;
	while(map->str[++i])
	{
		j = -1;
		while(map->str[i][++j])
			draw(map, i, j);
	}
}

void    xpm_to_image(t_map *map)
{
	map->mlx = mlx_init();
	map->wall = mlx_xpm_file_to_image(map->mlx, WALL, &map->img_w, &map->img_h);
	map->empty = mlx_xpm_file_to_image(map->mlx, EMPTY, &map->img_w, &map->img_h);
	map->px = 500;
	map->py = 500;
	map->win = mlx_new_window(map->mlx, 960, 840, "cub3d");
}

int draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color)
{
	double deltaX = endX - beginX;
	double deltaY = endY - beginY;
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels; 
	double pixelX = beginX;
	double pixelY = beginY;
	while (pixels)
	{
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
	return (0);
}

void    cub3d_game(t_map *map)
{
	xpm_to_image(map);
	map_to_win(map);
	draw_player(map);
	mlx_hook(map->win, 2, 1L << 2, mouvement, map);
	// mlx_pixel_put(map->mlx, map->win, 200 ,100, 0x00ff0000);
	mlx_put_image_to_window(map->mlx, map->win, map->img_ptr, map->px, map->py);
	mlx_loop(map->mlx);
}