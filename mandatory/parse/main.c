/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:47:19 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/26 23:29:26 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "../raycasting/raycasting.h"

int	main(int ac, char **av)
{
	t_map	map;
	t_maze	data;
	int		i;

	initialize_data(&data);
	map_check(&data, ac, av);
	map.str = data.map;
	cub3d_game(&map);
	i = data.map_lenght;
	while (map.str[i])
		free(map.str[i++]);
	free(map.str);
}
