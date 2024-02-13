/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_mouve.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 01:23:40 by amessah           #+#    #+#             */
/*   Updated: 2023/05/26 21:27:15 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	w_mouve(t_map *map)
{
	if (map->player.walk_w == 1)
	{
		if (map->str[(int)floor(map->py / TILE_SIZE)] \
				[(int)floor((map->px + (cos(map->player.rotationangle) * \
				map->player.movespeed)) / TILE_SIZE)] != '1'
			&& map->str[(int)floor(map->py / TILE_SIZE)] \
				[(int)floor((map->px + (cos(map->player.rotationangle) * \
				map->player.movespeed)) / TILE_SIZE)] != '\0' )
		{
			map->px += cos(map->player.rotationangle) * map->player.movespeed;
		}
		if (map->str[(int)floor((map->py + (sin(map->player.rotationangle) * \
			map->player.movespeed)) / TILE_SIZE)][(int)floor(map->px / \
				TILE_SIZE)] != '1'
			&& map->str[(int)floor((map->py + (sin(map->player.rotationangle) * \
				map->player.movespeed)) / TILE_SIZE)] \
				[(int)floor(map->px / TILE_SIZE)] != '\0')
		{
			map->py += sin(map->player.rotationangle) * map->player.movespeed;
		}
	}
}

void	s_mouve(t_map *map)
{	
	if (map->player.walk_s == 1)
	{
		if (map->str[(int)floor(map->py / TILE_SIZE)] \
				[(int)floor((map->px - (cos(map->player.rotationangle) * \
				map->player.movespeed)) / TILE_SIZE)] != '1'
			&& map->str[(int)floor(map->py / TILE_SIZE)] \
				[(int)floor((map->px - (cos(map->player.rotationangle) * \
				map->player.movespeed)) / TILE_SIZE)] != '\0')
		{
			map->px -= cos(map->player.rotationangle) * map->player.movespeed;
		}
		if (map->str[(int)floor((map->py - (sin(map->player.rotationangle) * \
			map->player.movespeed)) / TILE_SIZE)] \
			[(int)floor(map->px / TILE_SIZE)] != '1'
			&& map->str[(int)floor((map->py - (sin(map->player.rotationangle) * \
				map->player.movespeed)) / TILE_SIZE)] \
				[(int)floor(map->px / TILE_SIZE)] != '\0')
		{
			map->py -= sin(map->player.rotationangle) * map->player.movespeed;
		}
	}
}

void	a_mouve(t_map *map)
{
	if (map->player.walk_a == 1)
	{
		if (map->str[(int)floor(map->py / TILE_SIZE)] \
			[(int)floor((map->px + (sin(map->player.rotationangle) * \
			map->player.movespeed)) / TILE_SIZE)] != '1'
			&& map->str[(int)floor(map->py / TILE_SIZE)] \
				[(int)floor((map->px + (sin(map->player.rotationangle) * \
				map->player.movespeed)) / TILE_SIZE)] != '\0')
		{
			map->px += sin(map->player.rotationangle) * map->player.movespeed;
		}
		if (map->str[(int)floor((map->py - \
			(cos(map->player.rotationangle) * map->player.movespeed)) / \
				TILE_SIZE)][(int)floor(map->px / TILE_SIZE)] != '1'
			&& map->str[(int)floor((map->py - \
				(cos(map->player.rotationangle) * map->player.movespeed)) / \
				TILE_SIZE)][(int)floor(map->px / TILE_SIZE)] != '\0')
		{
			map->py -= cos(map->player.rotationangle) * map->player.movespeed;
		}
	}
}

void	d_mouve(t_map *map)
{
	if (map->player.walk_d == 1)
	{
		if (map->str[(int)floor(map->py / TILE_SIZE)] \
			[(int)floor((map->px - sin(map->player.rotationangle) * \
			map->player.movespeed) / TILE_SIZE)] != '1'
			&& map->str[(int)floor(map->py / TILE_SIZE)] \
				[(int)floor((map->px - sin(map->player.rotationangle) * \
				map->player.movespeed) / TILE_SIZE)] != '\0' )
		{
			map->px -= sin(map->player.rotationangle) * map->player.movespeed;
		}
		if (map->str[(int)floor((map->py + \
			(cos(map->player.rotationangle) * map->player.movespeed)) / \
			TILE_SIZE)][(int)floor(map->px / TILE_SIZE)] != '1'
			&& map->str[(int)floor((map->py + \
				(cos(map->player.rotationangle) * map->player.movespeed)) / \
				TILE_SIZE)][(int)floor(map->px / TILE_SIZE)] != '\0')
		{
			map->py += cos(map->player.rotationangle) * map->player.movespeed;
		}
	}
}

void	update_player_place(t_map *map)
{
	w_mouve(map);
	s_mouve(map);
	a_mouve(map);
	d_mouve(map);
}
