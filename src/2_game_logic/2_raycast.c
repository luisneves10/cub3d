/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_raycast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 22:31:07 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/19 11:41:25 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//pus aqui as declaracoes para meter a funcao raycast em cima
void	init_ray(t_data *data, int x, t_ray *ray);
void	calculate_step_and_side_dist(t_data *data, t_ray *ray);
void	perform_dda(t_data *data, t_ray *ray);
void	calculate_distance_and_height(t_data *data, t_ray *ray, int x);
void	draw_vertical_line(t_img *img, int x, t_ray *ray);

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.line_len + x * (img.bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	raycast(t_data *data)
{
	int		x;
	t_ray	ray;

	//data->img.img_ptr = mlx_new_image(data->win.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	//data->img.addr = mlx_get_data_addr(data->img.img_ptr, &data->img.bpp,
	//								&data->img.line_len, &data->img.endian);
	x = 0;
	while (x < WIN_WIDTH)
	{
		init_ray(data, x, &ray);
		calculate_step_and_side_dist(data, &ray);
		perform_dda(data, &ray);
		calculate_distance_and_height(data, &ray, x);
		x++;
	}
	mlx_put_image_to_window(data->win.mlx_ptr, data->win.win_ptr,
						 data->img.img_ptr, 0, 0);
	//mlx_destroy_image(data->win.mlx_ptr, data->img.img_ptr);
	return (0);
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

void	calculate_distance_and_height(t_data *data, t_ray *ray, int x)
{
	double	wallX;
	double	step;
	double	texPos;
	int		texX;

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
		ray->draw_end = WIN_HEIGHT;

	if (ray->side == 0)
		wallX = data->player.player_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wallX = data->player.player_x + ray->perp_wall_dist * ray->ray_dir_x;
	wallX -= floor((wallX));

	texX = (int)(wallX * (double)(TEXTURE_SIZE));
	if(ray->side == 0 && ray->ray_dir_x > 0)
		texX = TEXTURE_SIZE - texX - 1;
	if(ray->side == 1 && ray->ray_dir_y < 0)
		texX = TEXTURE_SIZE - texX - 1;

	step = 1.0 * TEXTURE_SIZE / ray->line_height;
	texPos = (ray->draw_start - WIN_HEIGHT / 2 + ray->line_height / 2) * step;

	int				i = 0;
	int				y = ray->draw_start;
	int				texY;
	unsigned int	color;

	while (i < y)
		put_pixel_img(data->img, x, i++, data->mapinfo.texture[5].color); //ARRANJAR MANEIRA PARA DESCOBRIR SE O TETO E O [4] OU O [5]
	while (y < ray->draw_end)
	{
		texY = (int)texPos & (TEXTURE_SIZE - 1);
		texPos += step;
	    color = *(unsigned int *)(data->mapinfo.texture[0].img.addr
									+ texY * data->mapinfo.texture[0].img.line_len
									+ texX * (data->mapinfo.texture[0].img.bpp / 8));
		// NESTE MOMENTO IMAGEM ESTA INVERTIDA (HORIZONTAL)... NEED TO FIX
		put_pixel_img(data->img, x, y, color);
		y++;
	}
	i = y;
	while (i < WIN_HEIGHT)
		put_pixel_img(data->img, x, i++, data->mapinfo.texture[4].color); //ARRANJAR MANEIRA PARA DESCOBRIR SE O CHAO E O [4] OU O [5]
}
