/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_textures_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:35:15 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/07 13:14:59 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	get_text_path(t_data *data, int k)
{
	int		i;
	char	*str;

	str = data->mapinfo.file[k];
	i = 0;
	while (ft_iswhitespace(str[i]))
		i ++;
	while (!ft_iswhitespace(str[i]))
		i ++;
	while (ft_iswhitespace(str[i]))
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
	while (ft_iswhitespace(*str))
		str++;
	if (ft_strncmp(str, "NO", 2) == 0 && ft_iswhitespace(*(str + 2)))
		return ('N');
	else if (ft_strncmp(str, "SO", 2) == 0 && ft_iswhitespace(*(str + 2)))
		return ('S');
	else if (ft_strncmp(str, "WE", 2) == 0 && ft_iswhitespace(*(str + 2)))
		return ('W');
	else if (ft_strncmp(str, "EA", 2) == 0 && ft_iswhitespace(*(str + 2)))
		return ('E');
	else if (ft_strncmp(str, "F", 1) == 0 && ft_iswhitespace(*(str + 1)))
		return ('F');
	else if (ft_strncmp(str, "C", 1) == 0 && ft_iswhitespace(*(str + 1)))
		return ('C');
	else
		return (INVALID);
}
