/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_rays_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:43:30 by amessah           #+#    #+#             */
/*   Updated: 2023/05/28 01:49:41 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting_bonus.h"
#include "../parse_bonus/parse_bonus.h"

void	rays_direction(t_map *map, int i)
{
	if (map->rays[i].rayangle >= 0 && map->rays[i].rayangle <= PI)
	{
		map->rays[i].facingdown = 1;
		map->rays[i].facingup = 0;
	}
	else
	{
		map->rays[i].facingdown = 0;
		map->rays[i].facingup = 1;
	}
	if (map->rays[i].rayangle >= PI * 0.5 && map->rays[i].rayangle <= PI * 1.5)
	{
		map->rays[i].facingright = 0;
		map->rays[i].facingleft = 1;
	}
	else
	{
		map->rays[i].facingright = 1;
		map->rays[i].facingleft = 0;
	}
}

void	rays(t_map *map)
{
	float	rangle;
	int		i;

	rangle = map->player.rotationangle - ((FOV_ANGLE * (PI / 180)) / 2);
	i = 0;
	map->count += 1;
	while (i < map->num_rays)
	{
		map->rays[i].rayangle = normlize(rangle);
		map->rays[i].foundvwh = 0;
		map->rays[i].foundhwh = 0;
		rays_direction(map, i);
		cast(map, map->rays[i], i);
		rangle += (FOV_ANGLE * (PI / 180)) / map->num_rays;
		i++;
	}
}

void	the_first_intersction_calcul(t_map *map, int position)
{
	if (map->cast.hdist < map->cast.vdist)
	{
		map->cast.hitx = map->cast.nexthx;
		map->cast.hity = map->cast.nexthy;
		map->rays[position].foundhwh = 1;
		map->rays[position].foundvwh = 0;
		map->rays[position].distance = map->cast.hdist;
	}
	else
	{
		map->cast.hitx = map->cast.nextvx;
		map->cast.hity = map->cast.nextvy;
		map->rays[position].foundhwh = 0;
		map->rays[position].foundvwh = 1;
		map->rays[position].distance = map->cast.vdist;
	}
}

void	the_first_intersction(t_map *map, int position)
{
	map->cast.hdist = \
		distancebetwenpoint(map->px, map->py, \
			map->cast.nexthx, map->cast.nexthy);
	map->cast.vdist = \
		distancebetwenpoint(map->px, map->py, \
			map->cast.nextvx, map->cast.nextvy);
	the_first_intersction_calcul(map, position);
}

void	cast(t_map *map, t_rays ray, int position)
{
	init_cast_variables(map);
	horizantal_intersection_calcul(map, ray);
	horizantal_intersection_loop(map, &ray);
	vertical_intersection_calcul(map, ray);
	vertical_intersection_loop(map, &ray);
	the_first_intersction(map, position);
	map->rays[position].hitx = map->cast.hitx;
	map->rays[position].hity = map->cast.hity;
	draw_line(map, map->cast.hitx * map->mini_map_scale, \
		map->cast.hity * map->mini_map_scale);
}
