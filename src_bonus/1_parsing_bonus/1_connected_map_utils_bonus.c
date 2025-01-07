/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_connected_map_utils_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:25:38 by daduarte          #+#    #+#             */
/*   Updated: 2025/01/07 13:16:10 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	init_counters(t_text_orientations *text_counters)
{
	text_counters->f = 0;
	text_counters->c = 0;
	text_counters->n = 0;
	text_counters->s = 0;
	text_counters->e = 0;
	text_counters->w = 0;
}

int	count_text(char c, t_text_orientations *text_counters)
{
	if (c == 'F')
		return (text_counters->f ++, VALID);
	else if (c == 'C')
		return (text_counters->c ++, VALID);
	else if (c == 'N')
		return (text_counters->n ++, VALID);
	else if (c == 'S')
		return (text_counters->s ++, VALID);
	else if (c == 'E')
		return (text_counters->e ++, VALID);
	else if (c == 'W')
		return (text_counters->w ++, VALID);
	else
		return (INVALID);
}

int	all_textures(t_text_orientations *text_counters)
{
	if (text_counters->f == 1 && text_counters->c == 1 && text_counters->n == 1
		&& text_counters->s == 1 && text_counters->e == 1
		&& text_counters->w == 1)
		return (VALID);
	return (INVALID);
}

int	get_new_length(char *str)
{
	int		i;
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
	return (new_length);
}
