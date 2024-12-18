/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:37 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/17 12:33:16 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		return (error_msg("Usage: ./cub3d <map_file.cub>", 1));
	init_data(&data);
	if (parse_file(&data, argv) == INVALID)
		return (INVALID);
	init_player(&data);
	ft_putstr_fd(BOLD GREEN"Valid file! "RESET, 1);
	ft_putendl_fd(GREEN"Starting cub3d..."RESET, 1);
	init_mlx(&data);
	mlx_loop_hook(data.win.mlx_ptr, raycast, &data);
	keypresses(&data);
	mlx_loop(data.win.mlx_ptr);
}
