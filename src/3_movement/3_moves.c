/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:30:43 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/18 18:41:14 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void move_forward(t_data *data)
{
	if (data->mapinfo.map[(int)(data->player.player_y)][(int)(data->player.player_x + data->player.player_dir_x * MOVE_SPEED)] != '1')
		data->player.player_x += data->player.player_dir_x * MOVE_SPEED;
	if (data->mapinfo.map[(int)(data->player.player_y + data->player.player_dir_y * MOVE_SPEED)][(int)(data->player.player_x)] != '1')
		data->player.player_y += data->player.player_dir_y * MOVE_SPEED;
}

void move_backward(t_data *data)
{
	if (data->mapinfo.map[(int)(data->player.player_y)][(int)(data->player.player_x - data->player.player_dir_x * MOVE_SPEED)] != '1')
		data->player.player_x -= data->player.player_dir_x * MOVE_SPEED;
	if (data->mapinfo.map[(int)(data->player.player_y - data->player.player_dir_y * MOVE_SPEED)][(int)(data->player.player_x)] != '1')
		data->player.player_y -= data->player.player_dir_y * MOVE_SPEED;
}

void move_left(t_data *data)
{
	if (data->mapinfo.map[(int)(data->player.player_y)][(int)(data->player.player_x - data->player.plane_x * MOVE_SPEED)] != '1')
		data->player.player_x -= data->player.plane_x * MOVE_SPEED;
	if (data->mapinfo.map[(int)(data->player.player_y - data->player.plane_y * MOVE_SPEED)][(int)(data->player.player_x)] != '1')
		data->player.player_y -= data->player.plane_y * MOVE_SPEED;
}

void move_right(t_data *data)
{
	if (data->mapinfo.map[(int)(data->player.player_y)][(int)(data->player.player_x + data->player.plane_x * MOVE_SPEED)] != '1')
		data->player.player_x += data->player.plane_x * MOVE_SPEED;
	if (data->mapinfo.map[(int)(data->player.player_y + data->player.plane_y * MOVE_SPEED)][(int)(data->player.player_x)] != '1')
		data->player.player_y += data->player.plane_y * MOVE_SPEED;
}

void rotate_right(t_data *data)
{
	double rot_speed;
	double old_dir_x;
	double old_plane_x;

	rot_speed = 0.1;
	old_dir_x = data->player.player_dir_x;
	data->player.player_dir_x = data->player.player_dir_x * cos(rot_speed) - data->player.player_dir_y * sin(rot_speed);
	data->player.player_dir_y = old_dir_x * sin(rot_speed) + data->player.player_dir_y * cos(rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot_speed) - data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed) + data->player.plane_y * cos(rot_speed);
}

void rotate_left(t_data *data)
{
	double rot_speed;
	double old_dir_x;
	double old_plane_x;

	rot_speed = -0.1;
	old_dir_x = data->player.player_dir_x;
	data->player.player_dir_x = data->player.player_dir_x * cos(rot_speed) - data->player.player_dir_y * sin(rot_speed);
	data->player.player_dir_y = old_dir_x * sin(rot_speed) + data->player.player_dir_y * cos(rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot_speed) - data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed) + data->player.plane_y * cos(rot_speed);
}

int handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		quit_program(data);
	if (keycode == KEY_W)
		move_forward(data);
	if (keycode == KEY_S)
		move_backward(data);
	if (keycode == KEY_A)
		move_left(data);
	if (keycode == KEY_D)
		move_right(data);
	if (keycode == KEY_LEFT)
		rotate_left(data);
	if (keycode == KEY_RIGHT)
		rotate_right(data);
	return (0);
}

void	keypresses(t_data *data)
{
	mlx_hook(data->win.win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win.win_ptr, DestroyNotify,
		StructureNotifyMask, quit_program, data);
}
