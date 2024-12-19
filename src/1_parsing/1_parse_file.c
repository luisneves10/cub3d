/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:07:19 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/19 13:28:22 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->mapinfo.texture[i].orientation = is_text(data->mapinfo.file[i]);
		if (data->mapinfo.texture[i].orientation == INVALID)
			return (error_msg("Invalid texture/color", INVALID));
		if (get_text_path(data, i) == INVALID)
			return (INVALID);
		if (valid_texture(data->mapinfo.texture[i]) == INVALID)
			return (INVALID);
		i ++;
	}
	return (VALID);
}

int	parse_map(t_data *data)
{
	data->mapinfo.nb_lines = map_height(data);
	data->mapinfo.map = ft_calloc(data->mapinfo.nb_lines + 1, sizeof(char *));
	if (!data->mapinfo.map)
		return (INVALID);
	if (copy_map(data) == INVALID)
		return (error_msg("Missing map", INVALID));
	if (valid_map_chars(data) == INVALID)
		return (INVALID);
	if (validate_walls(data->mapinfo.map, data->mapinfo.nb_lines) == INVALID)
		return (INVALID);
	return (VALID);
}

int	copy_file(t_data *data)
{
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(data->mapinfo.path, O_RDONLY);
	tmp = ft_strdup("");
	if (fd < 0)
		return (free(tmp), error_msg("Invalid file", INVALID));
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		tmp = ft_strjoin_free(tmp, str);
		free(str);
	}
	if (tmp[0] == '\0')
		return (free(tmp), close(fd), error_msg("Empty file", INVALID));
	if (check_file(tmp) == INVALID)
		return (free(tmp), close(fd), INVALID);
	data->mapinfo.file = ft_split(tmp, '\n');
	return (free(tmp), close(fd), SUCCESS);
}

int	parse_file(t_data *data, char **argv)
{
	if (!is_dir(argv[1]) || !is_cub_extension(argv[1]) || !valid_file(argv[1]))
		return (INVALID);
	data->mapinfo.path = argv[1];
	if (copy_file(data) == INVALID)
		return (INVALID);
	if (parse_textures(data) == INVALID)
		return (free_all(data), INVALID);
	if (parse_map(data) == INVALID)
		return (free_all(data), INVALID);
	return (VALID);
}
