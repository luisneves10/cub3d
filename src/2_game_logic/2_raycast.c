/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_raycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:31:07 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/17 10:26:56 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//pus aqui as declaracoes para meter a funcao raycast em cima
void	init_ray(t_data *data, int x, t_ray *ray);
void	calculate_step_and_side_dist(t_data *data, t_ray *ray);
void	perform_dda(t_data *data, t_ray *ray);
void	calculate_distance_and_height(t_data *data, t_ray *ray);
void	draw_vertical_line(t_img *img, int x, t_ray *ray);
void	clear_image(t_img *img, int width, int height, int color);

void	raycast(t_data *data)
{
	int		x;
	t_ray	ray;

	clear_image(&data->img, WIN_WIDTH, WIN_HEIGHT, 0x000000);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(data, x, &ray);
		calculate_step_and_side_dist(data, &ray);
		perform_dda(data, &ray);
		calculate_distance_and_height(data, &ray);
		draw_vertical_line(&data->img, x, &ray);
		x++;
	}
}

void put_pixel(t_img *img, int x, int y, int color)
{
	int index;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return;
	index = (y * img->size_line) + (x * (img->bpp / 8));
	*(int *)(img->data + index) = color;
}

void	clear_image(t_img *img, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			put_pixel(img, x, y, color);
			x++;
		}
		y++;
	}
}

void	init_ray(t_data *data, int x, t_ray *ray)
{
	ray->camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->ray_dir_x = data->player.player_dir_x + data->player.plane_x * ray->camera_x;
	ray->ray_dir_y = data->player.player_dir_y + data->player.plane_y * ray->camera_x;
	ray->map_x = (int)data->player.player_x;
	ray->map_y = (int)data->player.player_y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	calculate_step_and_side_dist(t_data *data, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - data->player.player_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.player_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - data->player.player_y) * ray->delta_dist_y;
	}
}

void	perform_dda(t_data *data, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		//acho que ja nao acontece
		if (ray->map_x < 0 || ray->map_y < 0 || ray->map_x >= ft_strlen(data->mapinfo.map[ray->map_y]) || ray->map_y >= data->mapinfo.nb_lines)
		{
			printf("Fora dos limites: x=%d, y=%d\n", ray->map_x, ray->map_y); //debvug
			ray->hit = 1;
			break;
		}
		if (data->mapinfo.map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_distance_and_height(t_data *data, t_ray *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - data->player.player_x + (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - data->player.player_y + (1 - ray->step_y) / 2) / ray->ray_dir_y;
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

void	draw_vertical_line(t_img *img, int x, t_ray *ray)
{
	int	y;
	int	color;

	if (ray->side == 0)
		color = 0xFF0000;
	else
		color = 0x00FF00;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		put_pixel(img, x, y, color);
		y++;
	}
}
