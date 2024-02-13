/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_horiz_verti_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:47:32 by amessah           #+#    #+#             */
/*   Updated: 2023/05/27 22:45:08 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"
#include "../parse_bonus/parse_bonus.h"

void	init_cast_variables(t_map *map)
{
	map->cast.xstep = 0;
	map->cast.ystep = 0;
	map->cast.nexthx = 0;
	map->cast.nexthy = 0;
	map->cast.nexthx_temp = 0;
	map->cast.nexthy_temp = 0;
	map->cast.nextvx = 0;
	map->cast.nextvy = 0;
	map->cast.nextvx_temp = 0;
	map->cast.nextvytemp = 0;
}

void	horizantal_intersection_calcul(t_map *map, t_rays ray)
{
	map->cast.yintercept = floor(map->py / TILE_SIZE) * TILE_SIZE;
	if (ray.facingdown)
		map->cast.yintercept += TILE_SIZE;
	map->cast.xintercept = map->px + \
		(map->cast.yintercept - map->py) / tan(ray.rayangle);
	map->cast.ystep = TILE_SIZE;
	if (ray.facingup)
		map->cast.ystep *= -1;
	map->cast.xstep = TILE_SIZE / tan(ray.rayangle);
	if (ray.facingleft && map->cast.xstep > 0)
		map->cast.xstep *= -1;
	if (ray.facingright && map->cast.xstep < 0)
		map->cast.xstep *= -1;
	map->cast.nexthx = map->cast.xintercept;
	map->cast.nexthy = map->cast.yintercept;
	map->cast.nexthx_temp = map->cast.nexthx;
	map->cast.nexthy_temp = map->cast.nexthy;
	if (ray.facingup)
		map->cast.nexthy_temp--;
}

void	horizantal_intersection_loop(t_map *map, t_rays *ray)
{
	while (map->cast.nexthx_temp >= 0 && map->cast.nexthx_temp < \
		(map->maxlinelenght * TILE_SIZE) && map->cast.nexthy_temp >= 0 \
		&& map->cast.nexthy_temp < (map->number_line * TILE_SIZE))
	{
		if (map->str[(int)floor(map->cast.nexthy_temp / TILE_SIZE)] \
			[(int)floor(map->cast.nexthx_temp / TILE_SIZE)] == '1')
		{
			ray->foundhwh = 1;
			break ;
		}
		else
		{
			map->cast.nexthx += map->cast.xstep;
			map->cast.nexthy += map->cast.ystep;
			map->cast.nexthx_temp += map->cast.xstep;
			map->cast.nexthy_temp += map->cast.ystep;
		}
	}
}

void	vertical_intersection_calcul(t_map *map, t_rays ray)
{
	map->cast.xintercept = floor(map->px / TILE_SIZE) * TILE_SIZE;
	if (ray.facingright)
		map->cast.xintercept += TILE_SIZE;
	map->cast.yintercept = map->py + \
		(map->cast.xintercept - map->px) * tan(ray.rayangle);
	map->cast.xstep = TILE_SIZE;
	if (ray.facingleft)
		map->cast.xstep *= -1;
	map->cast.ystep = TILE_SIZE * tan(ray.rayangle);
	if (ray.facingup && map->cast.ystep > 0)
		map->cast.ystep *= -1;
	if (ray.facingdown && map->cast.ystep < 0)
		map->cast.ystep *= -1;
	map->cast.nextvx = map->cast.xintercept;
	map->cast.nextvy = map->cast.yintercept;
	map->cast.nextvx_temp = map->cast.nextvx;
	map->cast.nextvytemp = map->cast.nextvy;
	if (ray.facingleft)
		map->cast.nextvx_temp--;
}

void	vertical_intersection_loop(t_map *map, t_rays *ray)
{
	while (map->cast.nextvx_temp >= 0 && map->cast.nextvx_temp < \
		(map->maxlinelenght * TILE_SIZE) && map->cast.nextvytemp >= 0 \
		&& map->cast.nextvytemp < (map->number_line * TILE_SIZE))
	{
		if (map->str[(int)floor(map->cast.nextvytemp / TILE_SIZE)] \
			[(int)floor(map->cast.nextvx_temp / TILE_SIZE)] == '1')
		{
			ray->foundvwh = 1;
			break ;
		}
		else
		{
			map->cast.nextvx += map->cast.xstep;
			map->cast.nextvy += map->cast.ystep;
			map->cast.nextvx_temp += map->cast.xstep;
			map->cast.nextvytemp += map->cast.ystep;
		}
	}
}
