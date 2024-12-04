/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_parse_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 15:07:19 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/04 16:30:13 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_file(t_data *data, char **argv)
{
	(void)data; // REMOVER
	if (!is_dir(argv[1]) || !is_cub_extension(argv[1]) || !valid_file(argv[1]))
		return (1);
	return (0);
}
