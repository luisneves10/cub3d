/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:37 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/10 10:36:13 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_data data;

	(void)argv;
	if (argc != 2)
		return (error_msg("Usage: ./cub3d <map_file.cub>", 1));
	init_data(&data);
	if (parse_file(&data, argv) == INVALID)
		return (INVALID);
	ft_putendl_fd(BOLD ULINE GREEN"VALID FILE"RESET, 1); // REMOVE
	init_mlx(&data);
	// init texturas;
	// render images;
	mlx_loop(data.win.mlx_ptr);
}
