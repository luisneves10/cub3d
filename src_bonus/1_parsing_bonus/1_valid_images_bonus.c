/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_valid_images_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:23:16 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/07 13:15:02 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	is_xpm_extension(char *arg)
{
	int	i;

	i = 0;
	while (arg[i + 1])
		i++;
	if (arg[i] == 'm' && arg[i - 1] == 'p' && arg[i - 2] == 'x'
		&& arg[i - 3] == '.')
		return (1);
	return (error_msg("File: only .xpm images are valid", 0));
}

int	valid_texture(t_texture texture)
{
	if (texture.orientation == 'F' || texture.orientation == 'C')
		return (VALID);
	if (!is_dir(texture.path)
		|| !is_xpm_extension(texture.path))
		return (INVALID);
	//que verificacoes e preciso fazer?
	return (VALID);
}
