/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:23:07 by amessah           #+#    #+#             */
/*   Updated: 2023/05/27 22:45:23 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parse_bonus/parse_bonus.h"
#include "raycasting_bonus.h"

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

float	normlize(float rayngle)
{
	rayngle = remainder(rayngle, 2 * PI);
	if (rayngle < 0)
		rayngle = (2 * PI) + rayngle;
	return (rayngle);
}

float	distancebetwenpoint(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
