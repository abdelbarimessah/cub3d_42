/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:25:08 by amessah           #+#    #+#             */
/*   Updated: 2023/05/27 22:45:31 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_bonus/parse_bonus.h"
#include "raycasting_bonus.h"

int	max_line_lenght(char **str)
{
	int	i;
	int	count;

	i = 0;
	count = ft_strlen(str[i]);
	while (str[i])
	{
		if (count < ft_strlen(str[i]))
			count = ft_strlen(str[i]);
		i++;
	}
	return (count);
}

void	draw_line(t_map *map, float x2, float y2)
{
	map->line.color = GRAY2;
	map->line.x = map->px * map->mini_map_scale;
	map->line.y = map->py * map->mini_map_scale;
	map->line.dx = x2 - map->line.x;
	map->line.dy = y2 - map->line.y;
	map->line.step = fmaxf(abs(map->line.dy), abs(map->line.dx));
	map->line.xinc = map->line.dx / map->line.step;
	map->line. yinc = map->line.dy / map->line.step;
	while (map->line.step >= 0)
	{
		mlx_pixel_put(map->mlx, map->win, \
			round(map->line.x), round(map->line.y), map->line.color);
		map->line.x += map->line.xinc;
		map->line.y += map->line.yinc;
		map->line.step--;
	}
}

void	render_circle(t_map *map, int x, int y, int r)
{
	int	i;
	int	x1;
	int	y1;
	int	color;

	i = -1;
	color = RED;
	while (++i <= 360)
	{
		x1 = r * cos(i);
		y1 = r * sin(i);
		mlx_pixel_put(map->mlx, map->win, \
			x * map->mini_map_scale + x1 * map->mini_map_scale, \
			y * map->mini_map_scale + y1 * map->mini_map_scale, color);
	}
	map->player.rotationangle = normlize(map->player.rotationangle);
}
