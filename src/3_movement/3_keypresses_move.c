/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_keypresses_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:54:16 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/19 13:56:27 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player.player_x + data->player.player_dir_x * MOVE_SPEED);
	y = (int)(data->player.player_y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.player_x += data->player.player_dir_x * MOVE_SPEED;
	x = (int)(data->player.player_x);
	y = (int)(data->player.player_y + data->player.player_dir_y * MOVE_SPEED);
	if (data->mapinfo.map[y][x] != '1')
		data->player.player_y += data->player.player_dir_y * MOVE_SPEED;
}

void	move_backward(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player.player_x - data->player.player_dir_x * MOVE_SPEED);
	y = (int)(data->player.player_y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.player_x -= data->player.player_dir_x * MOVE_SPEED;
	x = (int)(data->player.player_x);
	y = (int)(data->player.player_y - data->player.player_dir_y * MOVE_SPEED);
	if (data->mapinfo.map[y][x] != '1')
		data->player.player_y -= data->player.player_dir_y * MOVE_SPEED;
}

void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player.player_x - data->player.plane_x * MOVE_SPEED);
	y = (int)(data->player.player_y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.player_x -= data->player.plane_x * MOVE_SPEED;
	x = (int)(data->player.player_x);
	y = (int)(data->player.player_y - data->player.plane_y * MOVE_SPEED);
	if (data->mapinfo.map[y][x] != '1')
		data->player.player_y -= data->player.plane_y * MOVE_SPEED;
}

void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->player.player_x + data->player.plane_x * MOVE_SPEED);
	y = (int)(data->player.player_y);
	if (data->mapinfo.map[y][x] != '1')
		data->player.player_x += data->player.plane_x * MOVE_SPEED;
	x = (int)(data->player.player_x);
	y = (int)(data->player.player_y + data->player.plane_y * MOVE_SPEED);
	if (data->mapinfo.map[y][x] != '1')
		data->player.player_y += data->player.plane_y * MOVE_SPEED;
}
