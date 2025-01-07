/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_utils_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:35:09 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/07 13:15:17 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
