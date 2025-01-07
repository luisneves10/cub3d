/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:25:06 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/07 13:13:45 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	set_direction_horizontal(t_data *data)
{
	if (data->mapinfo.direction == 'E')
	{
		data->player.dir_x = 1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = FOV;
	}
	if (data->mapinfo.direction == 'W')
	{
		data->player.dir_x = -1;
		data->player.dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -FOV;
	}
}

void	set_direction_vertical(t_data *data)
{
	if (data->mapinfo.direction == 'N')
	{
		data->player.dir_x = 0;
		data->player.dir_y = -1;
		data->player.plane_x = FOV;
		data->player.plane_y = 0;
	}
	else if (data->mapinfo.direction == 'S')
	{
		data->player.dir_x = 0;
		data->player.dir_y = 1;
		data->player.plane_x = -FOV;
		data->player.plane_y = 0;
	}
}

void	init_player(t_data *data)
{
	t_player	player;

	player.x = data->mapinfo.start.x + (0.49);
	player.y = data->mapinfo.start.y + (0.49);
	data->player = player;
	set_direction_vertical(data);
	set_direction_horizontal(data);
}
