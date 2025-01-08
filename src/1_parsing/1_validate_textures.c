/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_validate_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 09:59:38 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/27 10:02:03 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	unique_colors(t_data *data, int i)
{
	int	j;
	int	counter;

	j = 0;
	counter = 0;
	if (data->mapinfo.texture[i].orientation == 'C'
		|| data->mapinfo.texture[i].orientation == 'F')
	{
		while (j < 6)
		{
			if (data->mapinfo.texture[i].color
				== data->mapinfo.texture[j].color)
				counter ++;
			j ++;
		}
	}
	if (counter > 1)
		return (INVALID);
	return (VALID);
}

int	unique_textures(t_data *data)
{
	int	i;
	int	j;
	int	counter;

	i = -1;
	while (++i < 6)
	{
		counter = 0;
		j = -1;
		if (unique_colors(data, i) == INVALID)
			return (error_msg("Colors are not unique", INVALID));
		while (++j < 6)
		{
			if (ft_strncmp(data->mapinfo.texture[i].path,
					data->mapinfo.texture[j].path,
					ft_strlen(data->mapinfo.texture[i].path)) == 0
				&& ft_strlen(data->mapinfo.texture[i].path)
				== ft_strlen(data->mapinfo.texture[j].path))
				counter ++;
		}
		if (counter > 1)
			return (error_msg("Textures are not unique", INVALID));
	}
	return (VALID);
}

unsigned int	combine_rgb(int *rgb)
{
	if (!rgb)
		return (INVALID);
	return (((rgb[0] & 0xFF) << 16) | ((rgb[1] & 0xFF) << 8) | (rgb[2] & 0xFF));
}

int	is_valid_color(t_texture *texture)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	if (!ft_strchr(texture->path, ','))
		return (INVALID);
	rgb = ft_split(texture->path, ',');
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			while (ft_iswhitespace(rgb[i][j]))
				j ++;
			if (!ft_isdigit(rgb[i][j++]))
				return (free_split(rgb), INVALID);
		}
		texture->rgb[i] = ft_atoi(rgb[i]);
		i ++;
	}
	if (valid_rgb(texture->rgb, i) == INVALID)
		return (free_split(rgb), INVALID);
	texture->color = combine_rgb(texture->rgb);
	return (free_split(rgb), VALID);
}

int	valid_rgb(int *color, int size)
{
	int	i;

	i = 0;
	if (size != 3)
		return (INVALID);
	while (i < 3)
	{
		if (color[i] < 0 || color[i] > 255)
			return (INVALID);
		i ++;
	}
	return (VALID);
}
