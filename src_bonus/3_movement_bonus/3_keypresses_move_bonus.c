/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_keypresses_move_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:54:16 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/07 13:15:12 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_forward(t_data *data, double move_speed)
{
	int	x;
	int	y;

	x = (int)(data->player.x + data->player.dir_x * move_speed);
	y = (int)(data->player.y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.x += data->player.dir_x * move_speed;
	x = (int)(data->player.x);
	y = (int)(data->player.y + data->player.dir_y * move_speed);
	if (data->mapinfo.map[y][x] != '1')
		data->player.y += data->player.dir_y * move_speed;
}

void	move_backward(t_data *data, double move_speed)
{
	int	x;
	int	y;

	x = (int)(data->player.x - data->player.dir_x * move_speed);
	y = (int)(data->player.y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.x -= data->player.dir_x * move_speed;
	x = (int)(data->player.x);
	y = (int)(data->player.y - data->player.dir_y * move_speed);
	if (data->mapinfo.map[y][x] != '1')
		data->player.y -= data->player.dir_y * move_speed;
}

void	move_left(t_data *data, double move_speed)
{
	int	x;
	int	y;

	x = (int)(data->player.x - data->player.plane_x * move_speed);
	y = (int)(data->player.y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.x -= data->player.plane_x * move_speed;
	x = (int)(data->player.x);
	y = (int)(data->player.y - data->player.plane_y * move_speed);
	if (data->mapinfo.map[y][x] != '1')
		data->player.y -= data->player.plane_y * move_speed;
}

void	move_right(t_data *data, double move_speed)
{
	int	x;
	int	y;

	x = (int)(data->player.x + data->player.plane_x * move_speed);
	y = (int)(data->player.y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.x += data->player.plane_x * move_speed;
	x = (int)(data->player.x);
	y = (int)(data->player.y + data->player.plane_y * move_speed);
	if (data->mapinfo.map[y][x] != '1')
		data->player.y += data->player.plane_y * move_speed;
}
