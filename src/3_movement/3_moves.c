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

int	handle_keypress(int keycode, t_data *data)
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
