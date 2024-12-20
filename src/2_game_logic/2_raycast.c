/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_raycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:31:07 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/19 15:12:28 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	raycast(t_data *data)
{
	int		x;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(data, x, &ray);
		calculate_step_and_side_dist(data, &ray);
		perform_dda(data, &ray);
		calculate_distance_and_height(data, &ray);
		create_frame(data, &ray, x);
		x++;
	}
	return (0);
}

void	init_ray(t_data *data, int x, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir_x = data->player.dir_x
		+ data->player.plane_x * ray->camera_x;
	ray->dir_y = data->player.dir_y
		+ data->player.plane_y * ray->camera_x;
	ray->map_x = (int)data->player.x;
	ray->map_y = (int)data->player.y;
	ray->delta_x = fabs(1 / ray->dir_x);
	ray->delta_y = fabs(1 / ray->dir_y);
	ray->hit = 0;
}

void	calculate_step_and_side_dist(t_data *data, t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.x - ray->map_x)
			* ray->delta_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.x)
			* ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.y - ray->map_y)
			* ray->delta_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.y)
			* ray->delta_y;
	}
}

void	perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ray->map_x < 0 || ray->map_y < 0
			|| ray->map_x >= ft_strlen(data->mapinfo.map[ray->map_y])
			|| ray->map_y >= data->mapinfo.nb_lines)
		{
			ray->hit = 1;
			break ;
		}
		if (data->mapinfo.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_distance_and_height(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player.x
				+ (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player.y
				+ (1 - ray->step_y) / 2) / ray->dir_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT;
}
