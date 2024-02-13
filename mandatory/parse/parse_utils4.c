/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:11:02 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/27 21:23:39 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	custom_space(char **map, int i)
{
	if (map[i][0] == ' ' && map[i][1] == '\0')
		return (1);
	return (0);
}

void	check_map_items(t_maze *data, char **map, int i)
{
	int		j;

	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_not_item(map[i][j], data))
				ft_error ("items ");
			if (player_direction(data, map[i][j]))
			{
				data->player.px = j;
				data->player.py = i;
				data->player_count += 1;
			}
			j++;
		}
		i++;
	}
	if (data->player_count == 0)
		ft_error ("no player ");
	if (data->player_count > 1)
		ft_error("more than one player ");
}

void	map_is_valid(char **map, int start)
{
	int		i;
	int		j;
	int		len1;
	int		len2;

	i = start;
	j = 0;
	len1 = 0;
	len2 = 0;
	while (map[i] && map [i + 1])
	{
		j = 0;
		len1 = ft_strlen(map[i]);
		len2 = ft_strlen(map[i + 1]);
		check_line_diff(map, i, len1, len2);
		while (map[i][j] && map[i + 1])
		{
			check_space_surrounding (map, i, j);
			j++;
		}
		i++;
	}
}

void	check_line_diff(char **map, int i, int len1, int len2)
{
	char	*tmp;

	tmp = NULL;
	if (len1 > len2)
	{
		tmp = ft_substr(map[i], len2, len1 - len2);
		if (!is_wall(tmp, 5))
			ft_error("opened map 1");
	}
	else if (len2 > len1)
	{
		tmp = ft_substr(map[i + 1], len1, len2 - len1);
		if (!is_wall(tmp, 5))
			ft_error("opened map 11");
	}
	free(tmp);
}
