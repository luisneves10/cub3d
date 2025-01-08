/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_minimap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 14:22:22 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/08 15:15:50 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	draw_minimap(t_data *data)
{
	t_point	p;
	t_point	map;
	int		map_start_x;
	int		map_start_y;

	map_start_x = (int)data->player.x - (MM_WIDTH / 2 / MM_SCALE);
	map_start_y = (int)data->player.y - (MM_HEIGHT / 2 / MM_SCALE);
	p.y = 9;
	while (++p.y < MM_HEIGHT)
	{
		p.x = 9;
		while (++p.x < MM_WIDTH)
		{
			map.x = map_start_x + p.x / MM_SCALE - 1;
			map.y = map_start_y + p.y / MM_SCALE - 1;
			if (map.x >= 0 && map.y >= 0 && map.y < data->mapinfo.nb_lines
				&& map.x < ft_strlen(data->mapinfo.map[map.y]))
			{
				if (data->mapinfo.map[map.y][map.x] == '1')
					put_pixel_img(data->img, p.x, p.y, 0xFFFFFF);
				else
					put_pixel_img(data->img, p.x, p.y, 0x444444);
			}
		}
	}
}

void	draw_player_on_minimap(t_data *data)
{
	int	px;
	int	py;
	int	center_x;
	int	center_y;

	center_x = MM_WIDTH / 2 + 10;
	center_y = MM_HEIGHT / 2 + 10;
	py = -3;
	while (py <= 3)
	{
		px = -3;
		while (px <= 3)
		{
			put_pixel_img(data->img, center_x + px, center_y + py, 0xFF0000);
			px++;
		}
		py++;
	}
}

static void	init_vars(int *i, t_point *p, t_point *center)
{
	*i = 0;
	p->x = 0;
	p->y = 0;
	center->x = MM_WIDTH / 2 + 10;
	center->y = MM_HEIGHT / 2 + 10;
}

void	draw_pov_on_minimap(t_data *data)
{
	int		i;
	t_point	p;
	t_point	center;
	double	angle_end;
	double	angle_start;

	init_vars(&i, &p, &center);
	while (i < FOV_RADIUS * MM_SCALE)
	{
		angle_start = atan2(data->player.dir_y, data->player.dir_x) - M_PI / 6;
		angle_end = atan2(data->player.dir_y, data->player.dir_x) + M_PI / 6;
		while (angle_start <= angle_end)
		{
			p.x = center.x + cos(angle_start) * i;
			p.y = center.y + sin(angle_start) * i;
			if (p.x >= 0 && p.x < MM_WIDTH && p.y >= 0 && p.y < MM_HEIGHT)
				put_pixel_img(data->img, p.x, p.y, 0x00FF00);
			angle_start += 0.01;
		}
		i++;
	}
}
