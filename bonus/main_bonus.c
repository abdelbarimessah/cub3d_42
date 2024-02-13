/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:30:49 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/27 22:45:36 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus/parse_bonus.h"
#include "raycasting_bonus/raycasting_bonus.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_maze	data;

	initialize_data(&data);
	map_check(&data, ac, av);
	map.str = data.map;
	map.maze = &data;
	cub3d_game(&map);
}
