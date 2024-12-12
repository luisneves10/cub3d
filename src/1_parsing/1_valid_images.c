/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_valid_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:23:16 by daduarte          #+#    #+#             */
/*   Updated: 2024/12/12 12:23:33 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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