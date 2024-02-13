/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 20:25:08 by amessah           #+#    #+#             */
/*   Updated: 2023/05/28 02:03:42 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse/parse.h"
#include "raycasting.h"

int	max_line_lenght(char **str)
{
	int	i;
	int	count;

	i = 0;
	count = ft_strlen(str[i]);
	while (str[i])
	{
		if (count < ft_strlen(str[i]))
			count = ft_strlen(str[i]);
		i++;
	}
	return (count);
}