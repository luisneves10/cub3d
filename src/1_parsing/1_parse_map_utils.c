/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:47:22 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/11 13:35:26 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void    copy_map(t_data *data)
{
    int i;
    int height;
    int width;

    i = 6;
    height = 0;
	while (data->mapinfo.file[i])
	{
        width = 0;
        data->mapinfo.map[height] = ft_calloc(ft_strlen(data->mapinfo.file[i]) + 1, sizeof(char));
		while (width < ft_strlen(data->mapinfo.file[i]))
		{
			data->mapinfo.map[height][width] = data->mapinfo.file[i][width];
            width ++;
		}
        height ++;
        i ++;
	}
}