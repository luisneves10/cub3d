/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daduarte <daduarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:09:10 by luibarbo          #+#    #+#             */
/*   Updated: 2025/01/09 09:26:29 by daduarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/time.h>
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

# define FOV 0.66
# define MOVE_SPEED 2.0
# define ROT_SPEED 2.5

# define MM_WIDTH 150
# define MM_HEIGHT 150
# define MM_SCALE 10
# define FOV_RADIUS 2

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
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
	int		w;
	int		h;
}	t_win;

typedef struct s_ray
{
	double	camera_x;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	double	delta_x;
	double	delta_y;
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
	int	n;
	int	s;
	int	e;
	int	w;
}	t_text_orientations;

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
	int			nb_lines;
	char		*path;
	char		**file;
	char		**map;
	t_point		start;
	char		direction;
	t_texture	texture[6];
	double		tex_wall_x;
	double		tex_step;
	double		tex_pos;
	int			tex_x;
	int			tex_y;
}	t_mapinfo;

typedef struct s_data
{
	t_win		win;
	t_mapinfo	mapinfo;
	t_player	player;
	t_img		img;
	int			offset;
	int			key[7];
	t_img		sprite[8];
}	t_data;

/* ========================================================================== */
/*                                FUNCTIONS                                   */
/* ========================================================================== */

int		error_msg(char *msg, int code);
void	free_map(char **map, int height);

/*	INIT -------------------------------------------------------------------- */
void	init_data(t_data *data);
void	init_player(t_data *data);
int		init_mlx(t_data *data);
int		init_textures_imgs(t_data *data);
void	init_textures(t_data *data);
void	init_counters(t_text_orientations *text_counters);

/*	PARSE ------------------------------------------------------------------- */
int		parse_file(t_data *data, char **argv);
int		is_text(char *str);
int		get_text_path(t_data *data, int k);
int		map_height(t_data *data);
int		copy_map(t_data *data);
int		valid_map_chars(t_data *data);
int		valid_map_chars(t_data *data);
int		validate_walls(char **map, int height);
int		is_valid_char(char c);
int		check_file(char *str);
int		valid_texture(t_texture texture);
int		flood_fill(char **map, int map_height, int x, int y);
int		get_new_length(char *str);
int		all_textures(t_text_orientations *text_counters);
int		all_textures(t_text_orientations *text_counters);
int		unique_textures(t_data *data);
int		is_valid_color(t_texture *texture);
int		valid_rgb(int *color, int size);
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
void	draw_vertical_line(t_data *data, t_ray *ray, int x);

t_img	new_file_img(t_win window, char *file);
void	put_pixel_img(t_img img, int x, int y, int color);
void	put_pixel_img_transp(t_img img, int x, int y, int color);
int		get_texture_index(t_data *data, char orientation);
int		get_texture_orientation(t_data *data, t_ray *ray);

void	load_sprites(t_data *data);
void	draw_torch(t_data *data, t_img torch);
int		animate_movement(t_data *data);
int		animate_sprite(void);

void	draw_minimap_frame(t_data *data);
void	draw_minimap(t_data *data);
void	draw_player_on_minimap(t_data *data);
void	draw_pov_on_minimap(t_data *data);

int		color_gradient(int color, double step);
int		calculate_darkness(t_ray *ray);
int		apply_darkness(int color, int darkness);

/*	MOVEMENTS --------------------------------------------------------------- */
int		update_player(t_data *data, double delta_time);
void	keypresses(t_data *data);
int		handle_mouse_move(int x, int y, t_data *data);
int		handle_keypress(int keycode, t_data *data);
int		handle_keyrelease(int keycode, t_data *data);
void	rotate_left(t_data *data, double rot_speed);
void	rotate_right(t_data *data, double rot_speed);
void	move_forward(t_data *data, double move_speed);
void	move_backward(t_data *data, double move_speed);
void	move_left(t_data *data, double move_speed);
void	move_right(t_data *data, double move_speed);

/*	EXIT -------------------------------------------------------------------- */
void	clean_and_exit(t_data *data, int code);
int		quit_program(t_data *data);
void	free_split(char **split);
void	free_all(t_data *data, int i);
void	free_paths(t_data *data);
void	free_map(char **map, int height);

/*	UTILS ------------------------------------------------------------------- */
double	get_delta_time(void);

#endif
