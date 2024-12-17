/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_clean_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:08:00 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/17 12:33:14 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_and_exit(t_data *data, int code)
{
	if (!data)
		exit (code);
	if (data->win.mlx_ptr && data->win.win_ptr)
		mlx_destroy_window(data->win.mlx_ptr, data->win.win_ptr);
	if (data->win.mlx_ptr)
	{
		mlx_destroy_display(data->win.mlx_ptr);
		mlx_loop_end(data->win.mlx_ptr);
		free(data->win.mlx_ptr);
	}
	// free de mais cenas;
	exit (code);
}

int	quit_program(t_data *data)
{
	clean_and_exit(data, 0);
	return (0);
}
