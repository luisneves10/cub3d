/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_connected_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:10:14 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/19 15:29:15 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*replace_newline(char *str)
{
	int		j;
	int		i;
	char	*new_str;
	int		original_length;

	original_length = ft_strlen(str);
	new_str = malloc(get_new_length(str) + 1);
	if (!new_str)
		return (NULL);
	j = 0;
	i = 0;
	while (i < original_length)
	{
		if (str[i] == '\n')
		{
			new_str[j++] = '\x01';
			new_str[j++] = '\x05';
		}
		else
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

void	flood_fill2(char **map, int x, int y, int height)
{
	if (y == height - 1 && x == ft_strlen(map[y]) - 1
		&& map[y][x] && map[y][x] == '1')
	{
		map[y][x] = 'F';
		return ;
	}
	else if (x < 0 || y < 0 || y >= height || x >= ft_strlen(map[y]) - 1)
		return ;
	if (!map[y][x] || map[y][x] == 'F' || map[y][x] == ' ')
		return ;
	if (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'N'
		|| map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
		map[y][x] = 'F';
	flood_fill2(map, x + 1, y, height);
	flood_fill2(map, x - 1, y, height);
	flood_fill2(map, x, y + 1, height);
	flood_fill2(map, x, y - 1, height);
}

int	is_connected_map(char *str, int i)
{
	int		j;
	int		k;
	char	*tmp;
	char	**map;

	j = 0;
	tmp = replace_newline(&str[i]);
	map = ft_split(tmp, '\x05');
	free(tmp);
	while (map[j])
		j ++;
	flood_fill2(map, 0, 0, j);
	j = 0;
	while (map[j])
	{
		k = -1;
		while (map[j][++k])
		{
			if (map[j][k] == '1' || map[j][k] == '0' || map[j][k] == 'N'
				|| map[j][k] == 'S' || map[j][k] == 'E' || map[j][k] == 'W')
				return (free_split(map), INVALID);
		}
		j ++;
	}
	return (free_split(map), VALID);
}

int	check_file_return_cases(char *str, int i, t_text_orientations *counters)
{
	if (str[i] && str[i] != '1' && !count_text(str[i], counters))
		return (error_msg("Wrong formatting", INVALID));
	else if (str[i] && str[i] == '1' && all_textures(counters))
	{
		if (is_connected_map(str, i) == INVALID)
			return (error_msg("Map is not connected", INVALID));
		return (VALID);
	}
	else if (str[i] && str[i] == '1' && !all_textures(counters))
		return (error_msg("Wrong formatting", INVALID));
	return (VALID);
}

int	check_file(char *str)
{
	int					i;
	t_text_orientations	text_counter;

	init_counters(&text_counter);
	i = 0;
	while (1)
	{
		while (ft_iswhitespace(str[i]))
			i ++;
		if (str[i] && count_text(str[i], &text_counter))
		{
			while (str[i] && str[i] != '\n')
				i ++;
			if (str[i] && str[i] == '\n')
				continue ;
		}
		else if (!str[i])
			break ;
		if (check_file_return_cases(str, i, &text_counter) == INVALID)
			return (INVALID);
		else
			return (VALID);
	}
	return (error_msg("Invalid formating.", INVALID));//e invalid?
}
