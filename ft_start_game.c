/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:53:11 by amessah           #+#    #+#             */
/*   Updated: 2023/04/27 16:46:14 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	my_mlx_pixel_put(t_map *data, int x, int y, int color)
// {
// 	char	*dst;
// 	dst = data->img_addr + (y * data->size_line + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	draw(t_map *map, int i, int j)
{
	if (map->str[i][j] == '1')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->wall,
			j * map->img_h, i * map->img_h);	
	}
	else
	{
		mlx_put_image_to_window(map->mlx, map->win, map->empty,
			j * map->img_h, i * map->img_h);
	}
}

void print_rectangl(t_map *conf, int y, int x, int color)
{
    int i;
    int j;

    x *= 64;
    y *= 64;
    i = 0;
    while (i < 64)
    {
        j = 0;
        while (j < 64)
        {
            conf->img_addr[(int)((y + j) ) * 640 + (int)((x + i) )] = color;
            // conf->img.addr[(( (minimap * y) + (minimap * j)) * conf->player.width + (minimap * x) + (minimap * i))] = color;
            j++;
        }
        i++;
    }
}


void draw1(t_map *map, int i ,int j)
{

	if(map->str[i][j] == '1')
	{	
		print_rectangl(map, i, j, AQUA);
	}
	else
	{
		print_rectangl(map, i , j, GRAY1);
		// my_mlx_pixel_put(map, i, j, 0x000000);
	}
	// else
	// 	my_mlx_pixel_put(map, i, j, 0xFFFFFF);
	
}

void	draw_player(t_map *map)
{
	int i = 0;
	int j = 0;
	
	// map->img_ptr = mlx_new_image(map->mlx, 10, 10);
	// map->img_addr = mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel, &map->size_line, &map->endian);
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			// my_mlx_pixel_put(map, i, j, 0x00ff0000);
			draw_line(map->mlx,map->win, 640,360, 0, 0,0xFFFFFF);
			j++;
		}
		i++;
	}
}

void draw_player1(t_map *map)
{
	int i = 0;
	int j = 0;
	while(map->str[i])
	{
		j = 0;
		while(map->str[i][j])
		{
			if(map->str[i][j] == 'P')
			{
				// mlx_put_image_to_window(map->mlx, map->win, map->wall,
				// 						j * map->img_w, i * map->img_h);
				// map->img_ptr = mlx_new_image(map->mlx, 10,10 );

				// mlx_pixel_put(map->mlx, map->win, i, j, 0x000000);
				map->var = PI / 2;
				// map->px = (i * map->img_h);
				// map->py = (j * map->img_w);
				// my_mlx_pixel_put(map, i  + 10, j + 10 ,0xFFFFFF);
				// map->px = map->img_h / 2;
				// map->py = map->img_w / 2;
				map->px = i;
				map->py = j;
			}
			j++;	
		}
		i++;
	}
}

int    map_to_win(t_map *map)
{
	int i;
	int j;
	map->img_ptr = mlx_new_image(map->mlx,640, 576);
	map->img_addr = (int *)mlx_get_data_addr(map->img_ptr, &map->bits_per_pixel, &map->size_line, &map->endian);
	i = -1;
	while(map->str[++i])
	{
		j = 0;
		while(map->str[i][j])
		{
			draw1(map, i, j);
			j++;
		}
	}
	printf("%d %d\n", i ,j);
	return(0);
}

void    xpm_to_image(t_map *map)
{
	map->mlx = mlx_init();
	// map->wall = mlx_xpm_file_to_image(map->mlx, WALL, &map->img_w, &map->img_h);
	// map->empty = mlx_xpm_file_to_image(map->mlx, EMPTY, &map->img_w, &map->img_h);
	map->size_line = ft_strlen(map->str[1]) - 1;
	map->number_line = 0;
	while(map->str[map->number_line])
		map->number_line++;
	map->win = mlx_new_window(map->mlx, (map->size_line + 1) * 64, (map->number_line )* 64, "cub3d");
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
int	handle_keyrelease(int keysym, void *data)
{
	printf("Keyrelease: %d\n", keysym);
	return (0);
}

void    cub3d_game(t_map *map)
{
	xpm_to_image(map);
	map_to_win(map);
	draw_player1(map);
	// mlx_loop_hook(map->mlx, &map_to_win, map);
	mlx_hook(map->win, 2, 0, &mouvement, map);
	// mlx_hook(map->win, 3, 0, &handle_keyrelease, map);
	// map->img_ptr = mlx_new_image(map->mlx, 1,1 );
	mlx_loop(map->mlx);
}