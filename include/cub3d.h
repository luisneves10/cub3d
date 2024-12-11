/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:10 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/10 12:22:52 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
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

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define TEXTURE_SIZE 64

# define INVALID 0
# define VALID 1
# define FAILURE 1
# define SUCCESS 0

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w; // WIDTH
	int		h; // HEIGHT
}	t_win;

typedef struct s_texture
{
	char	orientation;
	char	*path;
	int		color[3];
}	t_texture;

typedef struct s_mapinfo
{
	int		nb_lines;
	char	*path;
	char	**file;
	char	**map;
	//int	colors[2][3];
	t_texture	texture[6];
}	t_mapinfo;

typedef struct s_data
{
	t_win		win;
	t_mapinfo	mapinfo;
}	t_data;

/* ========================================================================== */
/*                                FUNCTIONS                                   */
/* ========================================================================== */

int		error_msg(char *msg, int code);

/*	INIT -------------------------------------------------------------------- */
void	init_data(t_data *data);
void	init_mlx(t_data *data);

/*	PARSE ------------------------------------------------------------------- */
int		parse_file(t_data *data, char **argv);
int		is_texture(char *str);
int		get_text_path(t_data *data, int k);

/*	VALID ARG --------------------------------------------------------------- */
int		is_dir(char *arg);
int		valid_file(char *arg);
int		is_cub_extension(char *arg);

#endif
