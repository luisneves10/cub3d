/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_sprite_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:22:19 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/07 13:15:10 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	load_sprites(t_data *data)
{
	data->sprite[0] = new_file_img(data->win, "./textures/torch/torch00.xpm");
	data->sprite[1] = new_file_img(data->win, "./textures/torch/torch01.xpm");
	data->sprite[2] = new_file_img(data->win, "./textures/torch/torch02.xpm");
	data->sprite[3] = new_file_img(data->win, "./textures/torch/torch03.xpm");
	data->sprite[4] = new_file_img(data->win, "./textures/torch/torch04.xpm");
	data->sprite[5] = new_file_img(data->win, "./textures/torch/torch05.xpm");
	data->sprite[6] = new_file_img(data->win, "./textures/torch/torch06.xpm");
	data->sprite[7] = new_file_img(data->win, "./textures/torch/torch07.xpm");
}

void	draw_torch(t_data *data, t_img torch)
{
	t_point	p;
	int		color;

	p.y = 0;
	while (p.y < torch.h)
	{
		p.x = 0;
		while (p.x < torch.w)
		{
			color = *(unsigned int *)(torch.addr + (p.y * torch.line_len
						+ p.x * (torch.bpp / 8)));
			put_pixel_img_transp(data->img, (WIN_WIDTH - torch.w) + p.x,
				(WIN_HEIGHT - torch.h + 150 + data->offset) + p.y, color);
			p.x++;
		}
		p.y++;
	}
}

int	animate_movement(t_data *data)
{
	static int	offset = 0;
	static int	frame_counter = 0;
	int			frame_delay;

	frame_delay = 20; // Adjust for speed
	frame_counter++;
	if (frame_counter >= frame_delay)
	{
		frame_counter = 0;
		offset = (offset + 10) % 20; // Loop through frames
	}
	if (data->key[1] || data->key[2] || data->key[3] || data->key[4])
		data->offset = offset;
	return (0);
}


int	animate_sprite()
{
	static int	sprite = 0;
	static int	frame_counter = 0;
	int			frame_delay;

	frame_delay = 10; // Adjust for speed
	frame_counter++;
	if (frame_counter >= frame_delay)
	{
		frame_counter = 0;
		sprite = (sprite + 1) % 8; // Loop through frames (CHANGE ACCORDING TO NUMBER OF IMAGES)
	}
	return (sprite);
}
