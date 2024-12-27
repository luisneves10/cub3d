/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:30:43 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/27 16:48:57 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_player(t_data *data, double delta_time)
{
	double	move_speed;
	double	rot_speed;

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

void	keypresses(t_data *data)
{
	mlx_hook(data->win.win_ptr, MotionNotify, PointerMotionMask, handle_mouse_move, data);
	mlx_hook(data->win.win_ptr, KeyPress, KeyPressMask, handle_keypress, data);
	mlx_hook(data->win.win_ptr, KeyRelease,
		KeyReleaseMask, handle_keyrelease, data);
	mlx_hook(data->win.win_ptr, DestroyNotify,
		StructureNotifyMask, quit_program, data);
}
