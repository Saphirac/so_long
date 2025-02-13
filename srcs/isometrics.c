/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometrics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 03:14:14 by mcourtoi          #+#    #+#             */
/*   Updated: 2022/09/21 00:53:38 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_scale(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->n_points)
	{
		map->map[i][0] *= map->scale;
		map->map[i][1] *= map->scale;
		map->map[i][2] *= map->scale;
	}
}

void	apply_centering(t_map *map)
{
	int	i;

	i = -1;
	while (++i < map->n_points)
	{
		map->map[i][0] += map->center_x;
		map->map[i][1] += map->center_y;
	}
}

void	isometric_transform(t_map *map)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < map->n_points)
	{
		x = map->map[i][0];
		y = map->map[i][1];
		map->map[i][0] = (x - y) * cos(map->angle);
		map->map[i][1] = (x + y) * sin(map->angle) - map->map[i][2];
	}
}
