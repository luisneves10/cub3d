/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_darkness_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:20:48 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/08 14:54:53 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	color_gradient(int color, double step)
{
	int	new_color;
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = (int)(r * (step));
	g = (int)(g * (step));
	b = (int)(b * (step));
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	new_color = (r << 16) | (g << 8) | b;
	return (new_color);
}

int	calculate_darkness(t_ray *ray)
{
	int	darkness;

	darkness = (int)((ray->perp_wall_dist / 2.5) * 255);
	if (darkness > 255)
		darkness = 255;
	return (darkness);
}

int	apply_darkness(int color, int darkness)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	r = r * (255 - darkness) / 255;
	g = g * (255 - darkness) / 255;
	b = b * (255 - darkness) / 255;
	return ((r << 16) | (g << 8) | b);
}
