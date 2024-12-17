/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:47:22 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/17 10:27:36 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_map(char **map, int height)
{
	int i;

	if (!map)
		return;
	i = 0;
	while (i < height)
	{
		if (map[i])
			free(map[i]);
		i++;
	}
	free(map);
}

int is_valid_char(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W'
		&& !is_whitespace(c))//verificar se e whitespace ou so ' '
		return (INVALID);
	return (VALID);
}

int map_height(t_data *data)
{
	int i;
	int height;

	i = 6;
	height = 0;
	while (data->mapinfo.file[i])
	{
		height ++;
		i ++;
	}
	return (height);
}
