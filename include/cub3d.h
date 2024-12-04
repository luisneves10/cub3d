/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luibarbo <luibarbo@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:10 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/04 11:10:12 by luibarbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <math.h>
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "colors.h"
# include "../minilibx-linux/mlx.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

# define TEXTURE_SIZE 64

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w; // WIDTH
	int		h; // HEIGHT
}	t_win;

typedef struct s_mapinfo
{
	int		nb_lines;
	int		fd;
	char	*path;
	char	**file; // FILE COPY
}	t_mapinfo;

typedef struct s_data
{
	t_win		win;
	t_mapinfo	mapinfo;

}	t_data;

/* ========================================================================== */
/*                                FUNCTIONS                                   */
/* ========================================================================== */

int		error_msg(char *topic, char *msg, int code);

/*	INIT -------------------------------------------------------------------- */
void	init_data(t_data *data);
void	init_mlx(t_data *data);

/*	PARSE ------------------------------------------------------------------- */
int		parse_file(t_data *data, char **argv);

/*	VALID ARG --------------------------------------------------------------- */
int		is_dir(char *arg);
int		valid_file(char *arg);
int		is_cub_extension(char *arg);

#endif
