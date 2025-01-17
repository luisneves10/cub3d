/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:37 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/08 15:13:14 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	game_loop(t_data *data)
{
	double	delta_time;
	t_img	torch;

	delta_time = get_delta_time();
	torch = data->sprite[animate_sprite()];
	update_player(data, delta_time);
	raycast(data);
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

int	quit_program(t_data *data)
{
	clean_and_exit(data, 0);
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
	load_sprites(&data);
	mlx_loop_hook(data.win.mlx_ptr, game_loop, &data);
	keypresses(&data);
	mlx_loop(data.win.mlx_ptr);
}
