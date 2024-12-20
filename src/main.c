/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:37 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/19 15:16:16 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_loop(t_data *data)
{
	double	delta_time;

	delta_time = get_delta_time();
	update_player(data, delta_time);
	raycast(data);
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
	mlx_loop_hook(data.win.mlx_ptr, game_loop, &data);
	keypresses(&data);
	mlx_loop(data.win.mlx_ptr);
}
