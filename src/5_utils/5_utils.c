/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:35:09 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/27 16:40:04 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double get_delta_time()
{
	static struct timeval last_time;
	struct timeval current_time;
	double delta_time;

	gettimeofday(&current_time, NULL);
	delta_time = (current_time.tv_sec - last_time.tv_sec) +
			(current_time.tv_usec - last_time.tv_usec) / 1000000.0;
	last_time = current_time;
	return (delta_time);
}
