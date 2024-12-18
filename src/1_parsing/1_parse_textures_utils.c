/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_textures_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:35:15 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/18 12:59:58 by daduarte         ###   ########.fr       */
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
			while (is_whitespace(rgb[i][j]))
				j ++;
			if (!ft_isdigit(rgb[i][j++]))
				return (free(rgb), INVALID); //free_split
		}
		texture->color[i] = ft_atoi(rgb[i]);
		i ++;
	}
	if (valid_rgb(texture->color, i) == INVALID)
		return (free(rgb), INVALID); //free_split
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
	if (!(*(str + i)))
		return (error_msg("Missing texture path", INVALID));
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

int	is_text(char *str)
{
	while (is_whitespace(*str))
		str++;
	if (ft_strncmp(str, "NO", 2) == 0 && is_whitespace(*(str + 2)))
		return ('N');
	else if (ft_strncmp(str, "SO", 2) == 0 && is_whitespace(*(str + 2)))
		return ('S');
	else if (ft_strncmp(str, "WE", 2) == 0 && is_whitespace(*(str + 2)))
		return ('W');
	else if (ft_strncmp(str, "EA", 2) == 0 && is_whitespace(*(str + 2)))
		return ('E');
	else if (ft_strncmp(str, "F", 1) == 0 && is_whitespace(*(str + 1)))
		return ('F');
	else if (ft_strncmp(str, "C", 1) == 0 && is_whitespace(*(str + 1)))
		return ('C');
	else
		return (INVALID);
}
