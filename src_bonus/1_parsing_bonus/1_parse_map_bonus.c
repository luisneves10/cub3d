/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:40:09 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/07 13:24:46 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	check_cell(char **temp_map, int height, int x, int y)
{
	if (temp_map[y][x] == '0' || temp_map[y][x] == 'N'
		|| temp_map[y][x] == 'S' || temp_map[y][x] == 'E'
		|| temp_map[y][x] == 'W')
	{
		if (flood_fill(temp_map, height, x, y) == INVALID)
			return (error_msg("Not closed map", INVALID));
	}
	return (VALID);
}

int	validate_walls(char **map, int height)
{
	int		y;
	int		x;
	char	**temp_map;

	y = 0;
	temp_map = ft_calloc(height + 1, sizeof(char *));
	while (y < height)
	{
		temp_map[y] = ft_strdup(map[y]);
		y++;
	}
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < ft_strlen(temp_map[y]))
		{
			if (check_cell(temp_map, height, x, y) == INVALID)
				return (free_map(temp_map, height), INVALID);
			x ++;
		}
		y ++;
	}
	return (free_map(temp_map, height), VALID);
}

void	check_player_position(t_data *data, int x, int y, int *player_count)
{
	if (data->mapinfo.map[y][x] == 'N'
		|| data->mapinfo.map[y][x] == 'S'
		|| data->mapinfo.map[y][x] == 'E'
		|| data->mapinfo.map[y][x] == 'W')
	{
		data->mapinfo.start.x = x;
		data->mapinfo.start.y = y;
		data->mapinfo.direction = data->mapinfo.map[y][x];
		(*player_count)++;
	}
}

int	valid_map_chars(t_data *data)
{
	int	height;
	int	width;
	int	player_count;

	player_count = 0;
	height = 0;
	while (data->mapinfo.map[height])
	{
		width = 0;
		while (data->mapinfo.map[height][width])
		{
			if (is_valid_char(data->mapinfo.map[height][width]) == INVALID)
				return (error_msg("Invalid char in map", INVALID));
			check_player_position(data, width, height, &player_count);
			width ++;
		}
		height ++;
	}
	if (player_count != 1)
		return (error_msg("Only 1 player position is valid", INVALID));
	return (VALID);
}

int	copy_map(t_data *data)
{
	int	i;
	int	height;

	i = 6;
	height = 0;
	while (data->mapinfo.file[i])
	{
		data->mapinfo.map[height] = ft_strdup(data->mapinfo.file[i]);
		height ++;
		i ++;
	}
	if (height == 0)
		return (INVALID);
	return (VALID);
}
