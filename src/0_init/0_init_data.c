/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:38:45 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/18 12:00:41 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_win(t_win *win)
{
	win->mlx_ptr = NULL;
	win->win_ptr = NULL;
	win->w = WIN_WIDTH;
	win->h = WIN_HEIGHT;
}

static void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->nb_lines = 0;
	mapinfo->path = NULL;
	mapinfo->file = NULL;
	mapinfo->start_pos.x = -1;
	mapinfo->start_pos.y = -1;
}

void set_player_direction(t_data *data)
{
	if (data->mapinfo.direction == 'N')
	{
		data->player.player_dir_x = 0;
		data->player.player_dir_y = -1;
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
	else if (data->mapinfo.direction == 'S')
	{
		data->player.player_dir_x = 0;
		data->player.player_dir_y = 1;
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	else if (data->mapinfo.direction == 'E')
	{
		data->player.player_dir_x = 1;
		data->player.player_dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	else if (data->mapinfo.direction == 'W')
	{
		data->player.player_dir_x = -1;
		data->player.player_dir_y = 0;
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
}

void	init_player(t_data *data)
{
	t_player	player;

	player.player_x = data->mapinfo.start_pos.x + (0.49);//VERIFICAR O CENTRO DO QUADRADO
	player.player_y = data->mapinfo.start_pos.y + (0.49);//VERIFICAR O CENTRO DO QUADRADO
	data->player = player;
	set_player_direction(data);
}

void	init_data(t_data *data)
{
	init_win(&data->win);
	init_mapinfo(&data->mapinfo);
}
