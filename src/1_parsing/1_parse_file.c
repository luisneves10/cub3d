/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:07:19 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/12 12:13:12 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    print_map(t_data *data) //remove
{
    int i = 0;
    int j = 0;

    while (data->mapinfo.file[i])
	{
        j = 0;
		while (data->mapinfo.file[i][j])
		{
			printf("%c ", data->mapinfo.file[i][j]);
            j ++;
		}
		printf("\n");
        i ++;
	}
}

int	parse_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->mapinfo.texture[i].orientation = is_texture(data->mapinfo.file[i]);
		if (data->mapinfo.texture[i].orientation == INVALID)
			return (error_msg("Invalid texture/color", INVALID));
		if (get_text_path(data, i) == INVALID)
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
	print_map(data);
	return (VALID);
}

int	copy_file(t_data *data)
{
	char	*str;
	char	*tmp;
	int		fd;

	fd = open(data->mapinfo.path, O_RDONLY);
	tmp = ft_strdup("");
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break;
		tmp = ft_strjoin(tmp, str);
		free(str);
	}
	if (tmp[0] == '\0')
		return (INVALID);
	data->mapinfo.file = ft_split(tmp, '\n');
	free (tmp);
	close(fd);
	return (SUCCESS);
}

int	parse_file(t_data *data, char **argv)
{
	if (!is_dir(argv[1]) || !is_cub_extension(argv[1]) || !valid_file(argv[1]))
		return (INVALID);
	data->mapinfo.path = argv[1];
	if (copy_file(data) == INVALID)
		return (error_msg("Empty file", INVALID));
	if (parse_textures(data) == INVALID)
		return (INVALID);
	if (parse_map(data) == INVALID)
		return (INVALID);
	return (VALID);
}
