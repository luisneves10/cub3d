/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_keypresses_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:54:16 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/19 15:15:16 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player.x + data->player.dir_x * MOVE_SPEED);
	y = (int)(data->player.y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.x += data->player.dir_x * MOVE_SPEED;
	x = (int)(data->player.x);
	y = (int)(data->player.y + data->player.dir_y * MOVE_SPEED);
	if (data->mapinfo.map[y][x] != '1')
		data->player.y += data->player.dir_y * MOVE_SPEED;
}

void	move_backward(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player.x - data->player.dir_x * MOVE_SPEED);
	y = (int)(data->player.y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.x -= data->player.dir_x * MOVE_SPEED;
	x = (int)(data->player.x);
	y = (int)(data->player.y - data->player.dir_y * MOVE_SPEED);
	if (data->mapinfo.map[y][x] != '1')
		data->player.y -= data->player.dir_y * MOVE_SPEED;
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player.x - data->player.plane_x * MOVE_SPEED);
	y = (int)(data->player.y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.x -= data->player.plane_x * MOVE_SPEED;
	x = (int)(data->player.x);
	y = (int)(data->player.y - data->player.plane_y * MOVE_SPEED);
	if (data->mapinfo.map[y][x] != '1')
		data->player.y -= data->player.plane_y * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player.x + data->player.plane_x * MOVE_SPEED);
	y = (int)(data->player.y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.x += data->player.plane_x * MOVE_SPEED;
	x = (int)(data->player.x);
	y = (int)(data->player.y + data->player.plane_y * MOVE_SPEED);
	if (data->mapinfo.map[y][x] != '1')
		data->player.y += data->player.plane_y * MOVE_SPEED;
}
