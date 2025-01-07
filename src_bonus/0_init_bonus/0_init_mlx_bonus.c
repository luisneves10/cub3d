/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_init_mlx_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:39:00 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/07 13:13:35 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	init_mlx(t_data *data)
{
	data->win.mlx_ptr = mlx_init();
	data->win.win_ptr = mlx_new_window(data->win.mlx_ptr,
			data->win.w, data->win.h, "cub3d");
	data->img.img_ptr = mlx_new_image(data->win.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img.w = WIN_WIDTH;
	data->img.h = WIN_HEIGHT;
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (init_textures_imgs(data) == INVALID)
		return (INVALID);
	return (0);
}
