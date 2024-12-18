/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_connected_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:10:14 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/17 14:53:40 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_flags(t_flags *flags)
{
	flags->f = 0;
	flags->c = 0;
	flags->n = 0;
	flags->s = 0;
	flags->e = 0;
	flags->w = 0;
}

int	is_flag(char c, t_flags *flags)
{
	if (c == 'F')
		return (flags->f ++, VALID);
	else if (c == 'C')
		return (flags->c ++, VALID);
	else if (c == 'N')
		return (flags->n ++, VALID);
	else if (c == 'S')
		return (flags->s ++, VALID);
	else if (c == 'E')
		return (flags->e ++, VALID);
	else if (c == 'W')
		return (flags->w ++, VALID);
	else
		return (INVALID);
}

int	all_textures(t_flags *flags)
{
	if (flags->f == 1 && flags->c == 1 && flags->n == 1 && flags->s == 1 && flags->e == 1 && flags->w == 1)
		return (VALID);
	return (INVALID);
}

char *replace_newline(const char *str)
{
	int		j;
	int		i;
	char	*new_str;
	int		new_length;
	int		original_length;

	new_length = 0;
	original_length = ft_strlen(str);
	i = 0;
	while (i < original_length)
	{
		if (str[i] == '\n')
			new_length += 2;
		else
			new_length += 1;
		i++;
	}
	new_str = malloc(new_length + 1);
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

void flood_fill2(char **map, int x, int y, int height)
{
	if (y == height - 1 && x == ft_strlen(map[y]) - 1 && map[y][x] && map[y][x] == '1')
	{
		map[y][x] = 'F';
		return;
	}
	else if (x < 0 || y < 0 || y >= height || x >= ft_strlen(map[y]) - 1)
		return;
	if (!map[y][x] || map[y][x] == 'F' || map[y][x] == ' ')
		return;
	if (map[y][x] == '1' || map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
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
	// print_map(map); //remove
	// printf("\n"); //remove
	while (map[j])
		j ++;
	flood_fill2(map, 0, 0, j);
	j = 0;
	while (map[j])
	{
		k = 0;
		while (map[j][k])
		{
			if (map[j][k] == '1' || map[j][k] == '0' || map[j][k] == 'N'
				|| map[j][k] == 'S' || map[j][k] == 'E' || map[j][k] == 'W')
				return (INVALID);
			k ++;
		}
		j ++;
	}
	// print_map(map); //remove
	return (VALID);
}

int	check_file(char *str)
{
	int	i;
	t_flags	flags;

	init_flags(&flags);
	i = 0;
	while (1)
	{
		while (is_whitespace(str[i]))
			i ++;
		if (str[i] && is_flag(str[i], &flags))
		{
			while (str[i] && str[i] != '\n')
				i ++;
			if (str[i] && str[i] == '\n')
				continue;
		}
		if (str[i] && str[i] != '1' && !is_flag(str[i], &flags))
			return (error_msg("Missing texture orientation", INVALID));
		else if (str[i] && str[i] == '1' && all_textures(&flags))
		{
			if (is_connected_map(str, i) == INVALID)
				return (error_msg("Map is not connected", INVALID));//remove
			return (/*ft_putendl_fd("Map is connected", 1), */VALID);
		}
		else if (str[i] && str[i] == '1' && !all_textures(&flags))
			return (error_msg("Missing or duplicated textures/colors", INVALID));
		else if (!str[i])
			break;
	}
	return (error_msg("Invalid formating.", INVALID));//NAO SEI SE E INVALID OU OUTRO NUM
}
