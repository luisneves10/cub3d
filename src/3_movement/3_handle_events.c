/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_handle_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:48:22 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/27 16:49:54 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	adjust_mouse_pos(int x, int y, t_data *data)
{
	if (x > WIN_WIDTH - 200)
	{
		x = 200;
		mlx_mouse_move(data->win.mlx_ptr, data->win.win_ptr, x, y);
	}
	if (x < 200)
	{
		x = WIN_WIDTH - 200;
		mlx_mouse_move(data->win.mlx_ptr, data->win.win_ptr, x, y);
	}
	if (y > WIN_HEIGHT - 200)
	{
		y = 200;
		mlx_mouse_move(data->win.mlx_ptr, data->win.win_ptr, x, y);
	}
	if (y < 200)
	{
		y = WIN_HEIGHT - 200;
		mlx_mouse_move(data->win.mlx_ptr, data->win.win_ptr, x, y);
	}
}

int	handle_mouse_move(int x, int y, t_data *data)
{
	static int	old_x = WIN_WIDTH / 2;

	mlx_mouse_hide(data->win.mlx_ptr, data->win.win_ptr);
	adjust_mouse_pos(x, y, data);
	if (x == old_x)
		return (0);
	if (x < old_x)
		rotate_left(data, 0.025);
	else if (x > old_x)
		rotate_right(data, 0.025);
	old_x = x;
	return (0);
}
