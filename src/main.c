/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:37 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/12 22:47:20 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int game_loop(t_data *data)
{
    raycast(data);
    mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr, data->img.img_ptr, 0, 0);
    return (0);
}

int	main(int argc, char **argv)
{
	t_data data;

	(void)argv;
	if (argc != 2)
		return (error_msg("Usage: ./cub3d <map_file.cub>", 1));
	init_data(&data);
	if (parse_file(&data, argv) == INVALID)
		return (INVALID);
    init_player(&data);
	ft_putendl_fd(BOLD ULINE GREEN"VALID FILE"RESET, 1); // REMOVE
	init_mlx(&data);
	data.img.img_ptr = mlx_new_image(data.win.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    data.img.data = mlx_get_data_addr(data.img.img_ptr, &data.img.bpp, &data.img.size_line, &data.img.endian);
	mlx_loop_hook(data.win.mlx_ptr, game_loop, &data);
    mlx_key_hook(data.win.win_ptr, handle_keypress, &data);

    mlx_loop(data.win.mlx_ptr);
}
