/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_directions_traitement_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:43:31 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/27 22:43:34 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parse_bonus.h"

void	aux_directions_traitement(t_maze *data, char *path, \
	int*flag, int start)
{
	if (path[start] == 'N' && path[start + 1] == 'O' \
		&& is_space(path[start + 2], 0))
		north_traitement(data, path, flag, start + 3);
	else if (path[start] == 'S' && path[start + 1] == 'O' \
		&& is_space(path[start + 2], 0))
		south_traitement(data, path, flag, start + 3);
	else if (path[start] == 'W' && path[start + 1] == 'E' \
		&& is_space(path[start + 2], 0))
		west_traitement(data, path, flag, start + 3);
	else if (path[start] == 'E' && path[start + 1] == 'A' \
		&& is_space(path[start + 2], 0))
		east_traitement(data, path, flag, start + 3);
	else if (path[start] == 'F' && is_space(path[start + 1], 0))
	{
		if (*flag != 4)
			ft_error("mesxsed up map ");
		floor_ceiling_traitement(data, path, flag, start + 2);
	}
	else if (path[start] == 'C' && is_space(path[start + 1], 0))
		floor_ceiling_traitement(data, path, flag, start + 2);
	else if (is_wall(path, 1) && *flag != 8)
		ft_error("messed up map ");
	else
		ft_error("directions ");
}
