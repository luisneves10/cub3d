/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:10 by luibarbo          #+#    #+#             */
/*   Updated: 2024/12/19 13:20:59 by daduarte         ###   ########.fr       */
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

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define TEXTURE_SIZE 64

# define INVALID 0
# define VALID 1
# define FAILURE 0
# define SUCCESS 1

# define MOVE_SPEED 0.25

typedef struct s_player {
	double player_x;
	double player_y;
	double player_dir_x;
	double player_dir_y;
	double plane_x;
	double plane_y;
}	t_player;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		w; // WIDTH
	int		h; // HEIGHT
}	t_win;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	hit;
	int		step_x;
	int		step_y;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_text_orientations
{
	int	f;
	int	c;
	int n;
	int	s;
	int	e;
	int	w;
} t_text_orientations;

typedef struct s_texture
{
	char			orientation;
	char			*path;
	int				rgb[3];
	unsigned int	color;
	t_img			img;
}	t_texture;

typedef struct s_mapinfo
{
	int		nb_lines;
	char	*path;
	char	**file;
	char	**map;
	t_point	start_pos;
	char	direction;
	t_texture	texture[6];
	double	tex_wall_x;
	double	tex_step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
}	t_mapinfo;

typedef struct s_data
{
	t_win		win;
	t_mapinfo	mapinfo;
	t_player	player;
	t_img		img;
}	t_data;

/* ========================================================================== */
/*                                FUNCTIONS                                   */
/* ========================================================================== */

void    print_map(char **map);

int		error_msg(char *msg, int code);
int		is_whitespace(char c);
void 	free_map(char **map, int height);

/*	INIT -------------------------------------------------------------------- */
void	init_data(t_data *data);
void	init_player(t_data *data);
void	init_mlx(t_data *data);
void	init_textures_imgs(t_data *data);
void	init_counters(t_text_orientations *text_counters);

/*	PARSE ------------------------------------------------------------------- */
int		parse_file(t_data *data, char **argv);
int		is_text(char *str);
int		get_text_path(t_data *data, int k);
int 	map_height(t_data *data);
int		copy_map(t_data *data);
int 	valid_map_chars(t_data *data);
int 	valid_map_chars(t_data *data);
int 	validate_walls(char **map, int height);
int 	is_valid_char(char c);
int		check_file(char *str);
int		valid_texture(t_texture texture);
int		flood_fill(char **map, int map_height, int x, int y);
int		get_new_length(char *str);
int		all_textures(t_text_orientations *text_counters);
int		count_text(char c, t_text_orientations *text_counters);

/*	VALID ARG --------------------------------------------------------------- */
int		is_dir(char *arg);
int		valid_file(char *arg);
int		is_cub_extension(char *arg);

/*	VALID TEXTURES ---------------------------------------------------------- */
int		is_xpm_extension(char *arg);

/*	RENDER ------------------------------------------------------------------ */
int		raycast(t_data *data);
void	init_ray(t_data *data, int x, t_ray *ray);
void	calculate_step_and_side_dist(t_data *data, t_ray *ray);
void	perform_dda(t_data *data, t_ray *ray);
void	calculate_distance_and_height(t_data *data, t_ray *ray);
void	put_pixel_img(t_img img, int x, int y, int color);
int		get_texture_index(t_data *data, char orientation);
int		get_texture_orientation(t_data *data, t_ray *ray);
void	create_frame(t_data *data, t_ray *ray, int x);

/*	MOVEMENTS --------------------------------------------------------------- */
void	keypresses(t_data *data);
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);

/*	EXIT -------------------------------------------------------------------- */
void	clean_and_exit(t_data *data, int code);
int		quit_program(t_data *data);
void	free_split(char **split);
void	free_all(t_data *data);
void	free_paths(t_data *data);
void	free_map(char **map, int height);

#endif
