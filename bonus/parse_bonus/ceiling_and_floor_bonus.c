/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 22:43:41 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/27 22:43:45 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "parse_bonus.h"

void	floor_ceiling_traitement(t_maze *data, char *color, \
	int *flag, int start)
{
	char		c;
	int			count;

	count = 0;
	while (color[start] == ' ' || color[start] == '\t')
	{
		count++;
		start++;
	}
	c = color[start - count - 2];
	if (c == 'F')
		data->lock_f += 1;
	else if (c == 'C')
		data->lock_c += 1;
	color = ft_strtrim(ft_strchr(color, color[start]), " \t");
	check_rgb(color);
	start = 0;
	if (color[start] >= '0' && color[start] <= '9')
		fill_floor_ceiling(data, color, c, flag);
	if (data->lock_f > 1 || data->lock_c > 1)
		*flag -= 2;
	free(color);
}

void	fill_floor_ceiling(t_maze *data, char *color, char f_or_c, int *flag)
{
	char	*to_check;
	int		flag_checker;

	flag_checker = 0;
	initialize_data(data);
	while (data->k < 3)
	{
		to_check = ft_substr(color, data->j, (size_t)rgb_len(color));
		while (color[data->j] && color[data->j] != ',')
			data->j++;
		data->j++;
		while (is_space(color[data->j], 0))
			data->j++;
		if (f_or_c == 'F')
			check_n_fill_rgb(data->floor_color, to_check, \
				data->i, &flag_checker);
		else if (f_or_c == 'C')
			check_n_fill_rgb(data->ceiling_color, to_check, \
				data->i, &flag_checker);
		data->i++;
		data->k++;
	}
	if (flag_checker == 3)
		*flag += 1;
}

int	is_wall(char *line, int flag)
{
	int		i;

	i = 0;
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (flag == 1)
		{
			while (line[i] == '1' || line[i] == '0' \
				|| line[i] == ' ' || player_direction(NULL, line[i]))
				i++;
		}
		is_only_wall(line, &i, flag);
		if (!line[i])
			return (1);
		else
			return (0);
	}
	return (-1);
}

void	is_only_wall(char *line, int *i, int flag)
{
	if (flag == 7)
	{
		while (line[*i] == '1')
			*i += 1;
	}
	else
	{
		while (line[*i] == '1' || line[*i] == ' ')
			*i += 1;
	}
}
