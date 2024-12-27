/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_minimap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:22:22 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/27 15:18:20 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap_frame(t_data *data)
{
	int	x;
	int	y;

	y = 8;
	while (y < MM_HEIGHT + 2)
	{
		x = 8;
		while (x < MM_WIDTH + 2)
			put_pixel_img(data->img, x++, y, 0x000000);
		y++;
	}
}

void draw_minimap(t_data *data)
{
	int	map_start_x;
	int	map_start_y;
	int	map_x;
	int	map_y;
	int	x;
	int	y;

	map_start_x = (int)data->player.x - (MM_WIDTH / 2 / MM_SCALE);
	map_start_y = (int)data->player.y - (MM_HEIGHT / 2 / MM_SCALE);
	y = 9;
	while (++y < MM_HEIGHT)
	{
		x = 9;
		while (++x < MM_WIDTH)
		{
			map_x = map_start_x + x / MM_SCALE - 1;
			map_y = map_start_y + y / MM_SCALE - 1;
			if (map_x >= 0 && map_y >= 0 && map_y < data->mapinfo.nb_lines
				&& map_x < ft_strlen(data->mapinfo.map[map_y]))
			{
				if (data->mapinfo.map[map_y][map_x] == '1')
					put_pixel_img(data->img, x, y, 0xFFFFFF);
				else
					put_pixel_img(data->img, x, y, 0x444444);
			}
		}
	}
}

void	draw_player_on_minimap(t_data *data)
{
	int	center_x;
	int	center_y;
	int	px;
	int	py;

    center_x = MM_WIDTH / 2 + 10;
    center_y = MM_HEIGHT / 2 + 10;
	py = -2;
	while (py <= 2)
	{
		px = -2;
		while (px <= 2)
		{
            put_pixel_img(data->img, center_x + px, center_y + py, 0xFF0000);
			px++;
		}
		py++;
	}
}

void	draw_pov_on_minimap(t_data *data)
{
	int	center_x;
	int	center_y;
	int	i;

	center_x = MM_WIDTH / 2 + 10;
	center_y = MM_HEIGHT / 2 + 10;
	i = 0;
	while (i < FOV_RADIUS * MM_SCALE)
	{
		double angle_start = atan2(data->player.dir_y, data->player.dir_x) - M_PI / 6;
		double angle_end = atan2(data->player.dir_y, data->player.dir_x) + M_PI / 6;

		for (double angle = angle_start; angle <= angle_end; angle += 0.01)
		{
			int x = center_x + cos(angle) * i;
			int y = center_y + sin(angle) * i;

			if (x >= 0 && x < MM_WIDTH && y >= 0 && y < MM_HEIGHT)
				put_pixel_img(data->img, x, y, 0x00FF00);
		}
		i++;
	}
}
