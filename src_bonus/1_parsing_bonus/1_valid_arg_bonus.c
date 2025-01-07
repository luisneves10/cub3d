/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_valid_arg_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:56:02 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/07 13:15:01 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_dir(char *arg)
{
	int	fd;

	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		return (error_msg("File: is a directory", INVALID));
	}
	return (VALID);
}

int	valid_file(char *arg)
{
	int	fd;

	fd = open(arg, O_RDONLY);
	if (fd < 0)
	{
		return (error_msg("File: Either the file doesn't exist or you don't"
				" have permission to open it", INVALID));
	}
	close(fd);
	return (VALID);
}

int	is_cub_extension(char *arg)
{
	int	i;

	i = 0;
	while (arg[i + 1])
		i++;
	if (arg[i] == 'b' && arg[i - 1] == 'u' && arg[i - 2] == 'c'
		&& arg[i - 3] == '.')
		return (VALID);
	return (error_msg("File: only .cub files are valid", INVALID));
}
