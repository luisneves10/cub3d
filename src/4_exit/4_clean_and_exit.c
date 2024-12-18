/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_clean_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:08:00 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/18 18:51:29 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	clean_and_exit(t_data *data, int code)
{
	if (!data)
		exit (code);
	free_paths(data);
	if (data->win.mlx_ptr && data->win.win_ptr)
		mlx_destroy_window(data->win.mlx_ptr, data->win.win_ptr);
	if (data->win.mlx_ptr)
	{
		mlx_destroy_display(data->win.mlx_ptr);
		mlx_loop_end(data->win.mlx_ptr);
		free(data->win.mlx_ptr);
	}
	free_all(data);
	exit (code);
}

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

	if (!data || !data->mapinfo.texture)
	{
		printf("Error: data or data->mapinfo.texture is NULL\n");
		return;
	}
	i = 0;
	while (i < 6)
	{
		if (data->mapinfo.texture[i].path != NULL)
		{
			free(data->mapinfo.texture[i].path);
			data->mapinfo.texture[i].path = NULL;
		}
		i ++;
	}
}

void	free_all(t_data *data)
{
	free_paths(data);
	free_split(data->mapinfo.file);
	free_map(data->mapinfo.map, data->mapinfo.nb_lines);
}

int	quit_program(t_data *data)
{
	clean_and_exit(data, 0);
	return (0);
}
