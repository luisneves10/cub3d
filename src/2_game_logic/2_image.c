/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_image.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:51:50 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/09 09:26:16 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_ceiling(t_data *data, t_ray *ray, int x)
{
	int		i;
	int		pixel;

	pixel = 0;
	i = get_texture_index(data, 'C');
	if (i < 0)
		return ;
	while (pixel < ray->draw_start)
	{
		put_pixel_img(data->img, x, pixel++, data->mapinfo.texture[i].color);
	}
}

static void	draw_wall(t_data *data, t_ray *ray, int x)
{
	int				i;
	int				pixel;
	int				color;

	pixel = ray->draw_start;
	i = get_texture_orientation(data, ray);
	if (i < 0)
		return ;
	while (pixel < ray->draw_end)
	{
		data->mapinfo.tex_y = (int)data->mapinfo.tex_pos & (TEXTURE_SIZE - 1);
		data->mapinfo.tex_pos += data->mapinfo.tex_step;
		color = *(unsigned int *)(data->mapinfo.texture[i].img.addr
				+ data->mapinfo.tex_y * data->mapinfo.texture[i].img.line_len
				+ data->mapinfo.tex_x * (data->mapinfo.texture[i].img.bpp / 8));
		put_pixel_img(data->img, x, pixel++, color);
	}
}

static void	draw_floor(t_data *data, t_ray *ray, int x)
{
	int		pixel;
	int		i;

	pixel = ray->draw_end;
	i = get_texture_index(data, 'F');
	if (i < 0)
		return ;
	while (pixel < WIN_HEIGHT)
	{
		put_pixel_img(data->img, x, pixel++, data->mapinfo.texture[i].color);
	}
}

void	get_pixels_position(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		data->mapinfo.tex_wall_x = data->player.y
			+ ray->perp_wall_dist * ray->dir_y;
	else
		data->mapinfo.tex_wall_x = data->player.x
			+ ray->perp_wall_dist * ray->dir_x;
	data->mapinfo.tex_wall_x -= floor((data->mapinfo.tex_wall_x));
	data->mapinfo.tex_x = (int)(data->mapinfo.tex_wall_x
			* (double)(TEXTURE_SIZE));
	if (ray->side == 0 && ray->dir_x < 0)
		data->mapinfo.tex_x = TEXTURE_SIZE - data->mapinfo.tex_x - 1;
	if (ray->side == 1 && ray->dir_y > 0)
		data->mapinfo.tex_x = TEXTURE_SIZE - data->mapinfo.tex_x - 1;
	data->mapinfo.tex_step = 1.0 * TEXTURE_SIZE / ray->line_height;
	data->mapinfo.tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * data->mapinfo.tex_step;
}

void	draw_vertical_line(t_data *data, t_ray *ray, int x)
{
	get_pixels_position(data, ray);
	draw_ceiling(data, ray, x);
	draw_wall(data, ray, x);
	draw_floor(data, ray, x);
}
