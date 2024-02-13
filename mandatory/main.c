/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 21:30:49 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/27 21:30:52 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse/parse.h"
#include "raycasting/raycasting.h"

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
