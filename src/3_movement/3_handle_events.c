/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_handle_events.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:48:22 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/07 12:49:13 by daduarte         ###   ########.fr       */
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
