/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:39:10 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/17 17:06:54 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_textures(t_data *data)
{
	int		i;
	t_img	img;

	i = 0;
	while (i < 4)
	{
		img = data->mapinfo.texture[i].img;
		img.img_ptr = mlx_xpm_file_to_image(data->win.mlx_ptr,
			data->mapinfo.texture[i].path, &img.w, &img.h);
		img.addr = mlx_get_data_addr(img.img_ptr, &(img.bpp),
			&(img.line_len), &(img.endian));
		i ++;
	}
}
