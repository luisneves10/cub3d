/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_map_utils_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:47:22 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/07 13:14:57 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	flood_fill(char **map, int map_height, int x, int y)
{
	if (y >= map_height || y < 0
		|| x < 0 || x >= ft_strlen(map[y]))
		return (INVALID);
	if (map[y][x] == 'F' || map[y][x] == '1')
		return (VALID);
	if (map[y][x] != '0' && map[y][x] != 'N' && map[y][x] != 'S' &&
		map[y][x] != 'E' && map[y][x] != 'W')
		return (INVALID);
	map[y][x] = 'F';
	if (flood_fill(map, map_height, x + 1, y) == INVALID
		|| flood_fill(map, map_height, x - 1, y) == INVALID
		|| flood_fill(map, map_height, x, y + 1) == INVALID
		|| flood_fill(map, map_height, x, y - 1) == INVALID)
		return (INVALID);
	return (VALID);
}

void	free_map(char **map, int height)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

int	is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& !ft_iswhitespace(c))
		return (INVALID);
	return (VALID);
}

int	map_height(t_data *data)
{
	int	i;
	int	height;

	i = 6;
	height = 0;
	while (data->mapinfo.file[i])
	{
		height ++;
		i ++;
	}
	return (height);
}
