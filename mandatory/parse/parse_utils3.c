/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:23:45 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/27 21:23:01 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	check_space_surrounding(char **map, int i, int j)
{
	if (map[i][j] == '0' && (is_space(map[i][j + 1], 1) || \
		is_space(map[i + 1][j], 1) || is_space(map[i - 1][j], 1) || \
		is_space(map[i][j - 1], 1)))
		ft_error ("opened map ");
}

void	store_map(char **map, t_maze *data)
{
	int		i;
	int		j;

	j = 0;
	i = data->start_map_index;
	data->map = malloc (sizeof(char *) * data->map_lenght + 1);
	while (map[i] != NULL)
	{
		data->map[j] = ft_strdup(map[i]);
		free(map[i]);
		i++;
		j++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] == ' ' && map[i][1] == '\0')
			free(map [i]);
		i++;
	}
	free(map);
	data->map[j] = NULL;
}

void	map_treatment(t_maze *data, char **map, int i)
{
	while (custom_space(map, i))
		i++;
	while (map[i] && map[i][0] == ' ' && !map[i][1])
		i++;
	if (is_wall(map[i], 2) == 1)
	{
		check_map_items(data, map, i);
		data->map_lenght = get_map_len(map, i);
		if (!is_wall(map[data->map_lenght + i - 1], 2))
			ft_error ("bottom wall ");
		data->start_map_index = i;
		map_is_valid(map, i + 1);
	}
	else
		ft_error ("map ");
	i++;
	store_map(map, data);
}

int	is_space(char c, int flag)
{
	if (flag)
	{
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0')
			return (1);
	}
	else
	{
		if (c == ' ' || c == '\t')
			return (1);
	}
	return (0);
}

int	get_map_len(char **map, int i)
{
	int		len;

	len = 0;
	while (map[i])
	{
		if (map[i][0] == ' ' && map[i][1] == '\0')
			ft_error ("splited map ");
		if (!is_wall(map[i], 1))
			break ;
		i++;
		len++;
	}
	return (len);
}
