/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:38:45 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/08 14:52:40 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
	mapinfo->start.x = -1;
	mapinfo->start.y = -1;
	mapinfo->map = NULL;
	mapinfo->direction = '\0';
}

static void	init_keys(int *key)
{
	key[0] = 0;
	key[1] = 0;
	key[2] = 0;
	key[3] = 0;
	key[4] = 0;
	key[5] = 0;
	key[6] = 0;
}

void	init_data(t_data *data)
{
	init_textures(data);
	init_win(&data->win);
	init_mapinfo(&data->mapinfo);
	init_keys(data->key);
	data->offset = 0;
}
