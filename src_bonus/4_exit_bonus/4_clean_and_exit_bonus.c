/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_clean_and_exit_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:08:00 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/07 13:15:15 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_paths(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (data->mapinfo.texture[i].orientation == 'C'
			|| data->mapinfo.texture[i].orientation == 'F')
		{
			if (data->mapinfo.texture[i].path)
				free(data->mapinfo.texture[i].path);
			data->mapinfo.texture[i].path = NULL;
			i ++;
		}
		else
		{
			if (data->mapinfo.texture[i].img.img_ptr)
				mlx_destroy_image(data->win.mlx_ptr,
					data->mapinfo.texture[i].img.img_ptr);
			if (data->mapinfo.texture[i].path)
				free(data->mapinfo.texture[i].path);
			data->mapinfo.texture[i].path = NULL;
			i ++;
		}
	}
}

void	free_sprite(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (data->sprite[i].img_ptr)
			mlx_destroy_image(data->win.mlx_ptr, data->sprite[i].img_ptr);
		i ++;
	}
}

void	free_all(t_data *data, int i)
{
	if (i)
		free_sprite(data);
	free_paths(data);//mudar nome
	free_split(data->mapinfo.file);
	free_map(data->mapinfo.map, data->mapinfo.nb_lines);
}

void	clean_and_exit(t_data *data, int code)
{
	if (!data)
		exit (code);
	free_all(data, 1);
	mlx_destroy_image(data->win.mlx_ptr, data->img.img_ptr);
	if (data->win.mlx_ptr && data->win.win_ptr)
		mlx_destroy_window(data->win.mlx_ptr, data->win.win_ptr);
	if (data->win.mlx_ptr)
	{
		mlx_destroy_display(data->win.mlx_ptr);
		mlx_loop_end(data->win.mlx_ptr);
		free(data->win.mlx_ptr);
	}
	exit (code);
}

int	quit_program(t_data *data)
{
	clean_and_exit(data, 0);
	return (0);
}
