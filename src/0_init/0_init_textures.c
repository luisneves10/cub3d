/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:39:10 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/19 15:24:05 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->mapinfo.texture[i].color = i - 10;
		data->mapinfo.texture[i].orientation = '\0';
		data->mapinfo.texture[i].path = NULL;
		data->mapinfo.texture[i].rgb[0] = -1;
		data->mapinfo.texture[i].rgb[1] = -1;
		data->mapinfo.texture[i].rgb[2] = -1;
		data->mapinfo.texture[i].img.img_ptr = NULL;
		i ++;
	}
}

int	init_textures_imgs(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (data->mapinfo.texture[i].orientation == 'C'
			|| data->mapinfo.texture[i].orientation == 'F')
			i ++;
		else
		{
			data->mapinfo.texture[i].img.img_ptr
				= mlx_xpm_file_to_image(data->win.mlx_ptr,
					data->mapinfo.texture[i].path,
					&data->mapinfo.texture[i].img.w,
					&data->mapinfo.texture[i].img.h);
			if (!data->mapinfo.texture[i].img.img_ptr)
				return (INVALID);
			data->mapinfo.texture[i].img.addr
				= mlx_get_data_addr(data->mapinfo.texture[i].img.img_ptr,
					&(data->mapinfo.texture[i].img.bpp),
					&(data->mapinfo.texture[i].img.line_len),
					&(data->mapinfo.texture[i].img.endian));
		}
	}
	return (0);
}
