/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 17:40:09 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/12 12:14:19 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int flood_fill(char **map, int map_height, int x, int y)
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

int validate_walls(char **map, int height)
{
    int i;
    int y;
    int x;
    char **temp_map;

    i = 0;
    temp_map = ft_calloc(height + 1, sizeof(char *));
    while (i < height)
    {
        temp_map[i] = ft_strdup(map[i]);
        i++;
    }
    y = 0;
    while (y < height)
    {
        x = 0;
        while (x < ft_strlen(temp_map[y]))
        {
            if (temp_map[y][x] == '0' || temp_map[y][x] == 'N' ||
                temp_map[y][x] == 'S' || temp_map[y][x] == 'E' || temp_map[y][x] == 'W')
            {
                if (flood_fill(temp_map, height, x, y) == INVALID)
                    return (free_map(temp_map, height), error_msg("Not closed map", INVALID));
            }
            x ++;
        }
        y ++;
    }
    free_map(temp_map, height);
    return (VALID);
}

int valid_map_chars(t_data *data)
{
    int height;
    int width;
    int player_count;

    player_count = 0;
    height = 0;
    while (data->mapinfo.map[height])
    {
        width = 0;
        while (data->mapinfo.map[height][width])
        {
            if (is_valid_char(data->mapinfo.map[height][width]) == INVALID)
                return (error_msg("Invalid char in map", INVALID));
            if (data->mapinfo.map[height][width] == 'N'
                || data->mapinfo.map[height][width] == 'S'
                || data->mapinfo.map[height][width] == 'E'
                || data->mapinfo.map[height][width] == 'W')
                player_count ++;
            width ++;
        }
        height ++;
    }
    if (player_count != 1)
        return (error_msg("Only 1 player position is valid", INVALID));
    return (VALID);
}

int    copy_map(t_data *data)
{
    int i;
    int height;

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