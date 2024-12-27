/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_image_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:23:44 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/27 15:51:20 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	put_pixel_img_transp(t_img img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	get_texture_index(t_data *data, char orientation)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->mapinfo.texture[i].orientation == orientation)
			return (i);
		i++;
	}
	return (-1);
}

int	get_texture_orientation(t_data *data, t_ray *ray)
{
	int	index;

	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			index = get_texture_index(data, 'W');
		else
			index = get_texture_index(data, 'E');
	}
	else
	{
		if (ray->dir_y > 0)
			index = get_texture_index(data, 'S');
		else
			index = get_texture_index(data, 'N');
	}
	return (index);
}
