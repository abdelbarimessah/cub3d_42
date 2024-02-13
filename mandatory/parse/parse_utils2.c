/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:13:46 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/26 23:43:22 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	initialize_data(t_maze *data)
{
	data->lock_c = 0;
	data->lock_f = 0;
	data->player_count = 0;
	data->i = 0;
	data->j = 0;
	data->k = 0;
}

int	player_direction(t_maze *data, char c)
{
	if (!data)
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			return (1);
	}
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (c == 'N')
			data->player.player_direction = NORTH;
		else if (c == 'S')
			data->player.player_direction = SOUTH;
		else if (c == 'E')
			data->player.player_direction = EAST;
		else if (c == 'W')
			data->player.player_direction = WEST;
		return (1);
	}
	return (0);
}

void	trimming_endofmap(char **map)
{
	int		i;

	i = 0;
	while (map[i + 1])
		i++;
	while (map[i] && custom_space(map, i))
	{
		free(map[i]);
		map[i] = NULL;
		i--;
	}
}

int	is_not_item(char c, t_maze *data)
{
	if (c != ' ' && c != '\t' && \
		c != '1' && c != '0' && \
			!player_direction(data, c))
		return (1);
	return (0);
}

void	rgb_valide_num(char *rgb, int *i)
{
	while (rgb[*i] && rgb[*i] != ',')
	{
		while (is_space(rgb[*i], 0))
			*i += 1;
		if (rgb[*i] == ',')
			break ;
		if (ft_isdigit(rgb[*i]))
			*i += 1;
		else
			ft_error("rgb 1");
	}
}
