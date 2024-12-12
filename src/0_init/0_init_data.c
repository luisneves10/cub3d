/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:38:45 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/11 16:32:12 by daduarte         ###   ########.fr       */
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
	mapinfo->player.x = -1;
	mapinfo->player.y = -1;
}

void	init_data(t_data *data)
{
	init_win(&data->win);
	init_mapinfo(&data->mapinfo);
}
