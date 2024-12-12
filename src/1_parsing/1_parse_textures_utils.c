/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_textures_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:35:15 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/12 12:06:35 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f')
		return (1);
	else
		return (0);
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

int	is_valid_color(t_texture *texture)
{
	int	i;
	int	j;
	char	*str;
	char	**rgb;

	i = 0;
	str = texture->path;
	if (!ft_strchr(str, ','))
		return (INVALID);
	rgb = ft_split(str, ',');
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (!ft_isdigit(rgb[i][j++]))
				return (free(rgb), INVALID);//free_split
		}
		texture->color[i] = ft_atoi(rgb[i]);
		i ++;
	}
	if (valid_rgb(texture->color, i) == INVALID)
	 	return (free(rgb), INVALID);//free_split
	return (VALID);
}

int	get_text_path(t_data *data, int k)
{
	int		i;
	char	*str;

	str = data->mapinfo.file[k];
	i = 0;
	while (is_whitespace(str[i]))
		i ++;
	while (!is_whitespace(str[i]))
		i ++;
	while (is_whitespace(str[i]))
		i ++;
	data->mapinfo.texture[k].path = ft_strdup(str + i);
	if (data->mapinfo.texture[k].orientation == 'F')
	{
		if (is_valid_color(&data->mapinfo.texture[k]) == INVALID)
			return (error_msg("Invalid floor color", INVALID));
	}
	if (data->mapinfo.texture[k].orientation == 'C')
	{
		if (is_valid_color(&data->mapinfo.texture[k]) == INVALID)
			return (error_msg("Invalid ceiling color", INVALID));
	}
	return (VALID);
}

int	is_texture(char *str)
{
	if (ft_strncmp(str, "NO ", 3) == 0)
		return ('N');
	else if (ft_strncmp(str, "SO ", 3) == 0)
		return ('S');
	else if (ft_strncmp(str, "WE ", 3) == 0)
		return ('W');
	else if (ft_strncmp(str, "EA ", 3) == 0)
		return ('E');
	else if (ft_strncmp(str, "F ", 2) == 0)
		return ('F');
	else if (ft_strncmp(str, "C ", 2) == 0)
		return ('C');
	else
		return (INVALID);
}
