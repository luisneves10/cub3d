/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_keypresses_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:54:46 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/19 13:55:04 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_data *data)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = 0.1;
	old_dir_x = data->player.player_dir_x;
	data->player.player_dir_x = data->player.player_dir_x * cos(rot_speed)
		- data->player.player_dir_y * sin(rot_speed);
	data->player.player_dir_y = old_dir_x * sin(rot_speed)
		+ data->player.player_dir_y * cos(rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot_speed)
		- data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed)
		+ data->player.plane_y * cos(rot_speed);
}

void	rotate_left(t_data *data)
{
	double	rot_speed;
	double	old_dir_x;
	double	old_plane_x;

	rot_speed = -0.1;
	old_dir_x = data->player.player_dir_x;
	data->player.player_dir_x = data->player.player_dir_x * cos(rot_speed)
		- data->player.player_dir_y * sin(rot_speed);
	data->player.player_dir_y = old_dir_x * sin(rot_speed)
		+ data->player.player_dir_y * cos(rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot_speed)
		- data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed)
		+ data->player.plane_y * cos(rot_speed);
}
