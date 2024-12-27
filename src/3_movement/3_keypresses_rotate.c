/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_keypresses_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 13:54:46 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/27 12:14:11 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_data *data, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(rot_speed) - data->player.dir_y * sin(rot_speed);
	data->player.dir_y = old_dir_x * sin(rot_speed) + data->player.dir_y * cos(rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(rot_speed) - data->player.plane_y * sin(rot_speed);
	data->player.plane_y = old_plane_x * sin(rot_speed) + data->player.plane_y * cos(rot_speed);
}

void	rotate_left(t_data *data, double rot_speed)
{
	double old_dir_x;
	double old_plane_x;

	old_dir_x = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(-rot_speed) - data->player.dir_y * sin(-rot_speed);
	data->player.dir_y = old_dir_x * sin(-rot_speed) + data->player.dir_y * cos(-rot_speed);
	old_plane_x = data->player.plane_x;
	data->player.plane_x = data->player.plane_x * cos(-rot_speed) - data->player.plane_y * sin(-rot_speed);
	data->player.plane_y = old_plane_x * sin(-rot_speed) + data->player.plane_y * cos(-rot_speed);
}
