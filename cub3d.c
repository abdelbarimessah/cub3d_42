/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:19:08 by amessah           #+#    #+#             */
/*   Updated: 2022/07/02 02:19:40 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	int	fd;
	t_map	map;

	if(argc == 2 && check_file_name(argv[1]))
	{
		fd = open(argv[1], O_RDONLY);
		if(fd < 0)
			write(1, "error in opening the file descriptor\n", 38);
		else
		{
			map.str = map_read(fd);
			// map.px = position_i(map.str);
			// map.py = position_j(map.str);
			cub3d_game(&map);
			// close(fd);
			// ft_free(map.str);
		}
	}
	else
		write(1, "check args\n", 12);
}