/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:37 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/27 15:50:26 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	animate_movement(t_data *data)
{
	static int offset = 0;
	int frame_delay = 20; // Adjust for speed
	static int frame_counter = 0;

	frame_counter++;
	if (frame_counter >= frame_delay) {
		frame_counter = 0;
		offset = (offset + 10) % 20; // Loop through frames
	}
	if (data->key[1] || data->key[2] || data->key[3] || data->key[4])
		data->offset = offset;
	return (0);
}

t_img	new_file_img(t_win window, char *file)
{
	t_img	image;

	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, file, &image.w, &image.h);
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}

void	load_sprites(t_data *data)
{
	data->sprite[0] = new_file_img(data->win, "./tile001.xpm");
	data->sprite[1] = new_file_img(data->win, "./tile002.xpm");
	data->sprite[2] = new_file_img(data->win, "./tile003.xpm");
	data->sprite[3] = new_file_img(data->win, "./tile004.xpm");
	data->sprite[4] = new_file_img(data->win, "./tile005.xpm");
	data->sprite[5] = new_file_img(data->win, "./tile006.xpm");
	data->sprite[6] = new_file_img(data->win, "./tile007.xpm");
	data->sprite[7] = new_file_img(data->win, "./tile000.xpm");
}

int	animate_sprite()
{
	static int sprite = 0;
	int frame_delay = 10; // Adjust for speed
	static int frame_counter = 0;

	frame_counter++;
	if (frame_counter >= frame_delay) {
		frame_counter = 0;
		sprite = (sprite + 1) % 8; // Loop through frames
	}
	return (sprite);
}

int	game_loop(t_data *data)
{
	double	delta_time;
	t_img torch;
	delta_time = get_delta_time();
	update_player(data, delta_time);
	raycast(data);

	torch = data->sprite[animate_sprite()];
	animate_movement(data);
	draw_torch(data, torch);
	draw_minimap_frame(data);
	draw_minimap(data);
	draw_pov_on_minimap(data);
	draw_player_on_minimap(data);

	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr,
		data->img.img_ptr, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (error_msg("Usage: ./cub3d <map_file.cub>", 1));
	init_data(&data);
	if (parse_file(&data, argv) == INVALID)
		return (INVALID);
	init_player(&data);
	ft_putstr_fd(BOLD GREEN"Valid file! "RESET, 1);
	ft_putendl_fd(GREEN"Starting cub3d..."RESET, 1);
	init_mlx(&data);
	load_sprites(&data); //mudar de sitio
	mlx_loop_hook(data.win.mlx_ptr, game_loop, &data);
	keypresses(&data);
	mlx_loop(data.win.mlx_ptr);
}
