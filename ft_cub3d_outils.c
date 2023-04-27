/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d_outils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amessah <amessah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:25:31 by amessah           #+#    #+#             */
/*   Updated: 2023/04/25 10:40:31 by amessah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	check_file_name(char *str)
{
	int		i;
	char	*str1;
	int		cont;

	i = 0;
	cont = 0;
	str1 = str;
	while (str1[i])
	{
		if (str1[i] == '.')
			cont++;
		i++;
	}
	if (cont != 1)
		return (0);
	i = ft_strlen(str);
	if (str == 0 || i < 5)
		return (0);
	if (ft_strcmp(str + (i - 4), ".cub") == 0)
		return (1);
	return (0);
}

char	*reader(int fd)
{
	char	*buff;
	char	*map;
	int		i;

	i = 1;
	buff = malloc(BUFFER_SIZE + 1);
	map = malloc(1);
	if (!buff || !map)
		return (NULL);
	while (i)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			// free(buff);
			return (NULL);
		}
		buff[i] = '\0';
		map = ft_strjoin(map, buff);
	}
	// free(buff);
	return (map);
}

char	**map_read(int fd)
{
	char	*map;
	char	**map_line;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = reader(fd);
	if (!map)
		return (0);
	while (map[i])
	{
		if ((map[i] == '\n' && map[i + 1] == '\n')
			|| ((map[i] == '\n' && map[i + 1] == '\0'))
			|| ((map[i] == '\n' && map[i - 1] == '\0')))
			return (NULL);
		i++;
	}
	map_line = ft_split(map, '\n');
	
	// free(map);
	return (map_line);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	k;
	size_t	a;
	char	*str;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (NULL);
	a = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((a + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (s1 && s2)
	{
		while (s1[i])
			str[k++] = s1[i++];
		i = 0;
		while (s2[i])
			str[k++] = s2[i++];
		str[k] = '\0';
		// free((char *)s1);
		return (str);
	}
	return (NULL);
}