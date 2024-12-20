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

double get_delta_time()
{
	static struct timeval last_time;
	struct timeval current_time;
	double delta_time;

	gettimeofday(&current_time, NULL);
	delta_time = (current_time.tv_sec - last_time.tv_sec) +
			(current_time.tv_usec - last_time.tv_usec) / 1000000.0;
	last_time = current_time;
	return (delta_time);
}

int	update_player(t_data *data, double delta_time)
{
	double move_speed;
	double rot_speed;

	move_speed = MOVE_SPEED * delta_time;
	rot_speed = ROT_SPEED * delta_time;
	if (data->key[0] == KEY_ESC)
		quit_program(data);
	if (data->key[1] == KEY_W)
		move_forward(data, move_speed);
	if (data->key[2] == KEY_S)
		move_backward(data, move_speed);
	if (data->key[3] == KEY_A)
		move_left(data, move_speed);
	if (data->key[4] == KEY_D)
		move_right(data, move_speed);
	if (data->key[5] == KEY_LEFT)
		rotate_left(data, rot_speed);
	if (data->key[6] == KEY_RIGHT)
		rotate_right(data, rot_speed);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		data->key[0] = KEY_ESC;
	if (keycode == KEY_W)
		data->key[1] = KEY_W;
	if (keycode == KEY_S)
		data->key[2] = KEY_S;
	if (keycode == KEY_A)
		data->key[3] = KEY_A;
	if (keycode == KEY_D)
		data->key[4] = KEY_D;
	if (keycode == KEY_LEFT)
		data->key[5] = KEY_LEFT;
	if (keycode == KEY_RIGHT)
		data->key[6] = KEY_RIGHT;
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == data->key[0])
		data->key[0] = 0;
	if (keycode == data->key[1])
		data->key[1] = 0;
	if (keycode == data->key[2])
		data->key[2] = 0;
	if (keycode == data->key[3])
		data->key[3] = 0;
	if (keycode == data->key[4])
		data->key[4] = 0;
	if (keycode == data->key[5])
		data->key[5] = 0;
	if (keycode == data->key[6])
		data->key[6] = 0;
	return (0);
}

void	keypresses(t_data *data)
{
	mlx_hook(data->win.win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win.win_ptr, KeyRelease,
		  KeyReleaseMask, handle_keyrelease, data);
	mlx_hook(data->win.win_ptr, DestroyNotify,
		StructureNotifyMask, quit_program, data);
}
