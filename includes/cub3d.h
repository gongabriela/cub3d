/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:13:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/09 15:11:55 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../includes/libft/libft.h"
# include "../minilibx/mlx.h"
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <sys/time.h>
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <unistd.h>

# define PI 3.14159265358979323846
# define MAP_WIDTH 10
# define MAP_HEIGHT 10
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define ESC 65307
# define SPEED 2
# define ANGLE_SPEED 0.03
# define BLOCK 50
# define FOV 50
# define NUM_RAYS 1280
# define RAY_STEP 1
# define DEBUG 0
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define PLAYER_RADIUS 10

typedef struct s_slice
{
	int	start;
	int	end;
	int	height;
}	t_slice;

typedef struct s_texture
{
	void	*img;
	int		*data;
	int		width;
	int		height;
	int		line_length;
	int		bits_per_pixel;
	int		endian;
}	t_texture;

typedef struct s_map
{
	char		*filename;
	int			filename_fd;
	char		*line;
	int			(*map)[MAP_WIDTH];
	char		*n_path;
	char		*s_path;
	char		*e_path;
	char		*w_path;
	int			c_rgb[3];
	int			f_rgb[3];
	int			player_pos[2];
	char		player_ori;
}	t_map;

typedef struct s_raycasting
{
	float	angle_step;
	float	ray_angle;
	float	posx;
	float	posy;
	float	raydirx;
	float	raydiry;
	int		mapx;
	int		mapy;
	float	deltadistx;
	float	deltadisty;
	float	sidedistx;
	float	sidedisty;
	int		stepx;
	int		stepy;
	int		side;
	float	distance;
}	t_raycasting;

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;
	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;
	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	t_player		player;
	t_raycasting	r;
	t_map			map_info;
	t_texture		n;
	t_texture		s;
	t_texture		e;
	t_texture		w;
	int				c_color;
	int				f_color;
}	t_game;

// debug_2d.c
void		ray_casting2d(t_game *game);

// debug_draw.c
void		draw_player(t_game *game);
void		draw_square(t_game *game, int start_x, int start_y, int color);
void		draw_map(t_game *game);

// draw_3d.c
void		draw_celling_floor(t_game *game);
t_texture	*get_correct_texture(t_game *g);
int			get_tex_x(t_game *g, t_texture *tex);
void		draw_tex_column(t_game *g, int x, t_slice slice, t_texture *tex);
void		draw_wall_slice_texture(t_game *g, int x, float dist);

// draw_utils.c
float		correct_fisheye(float distance,
				float ray_angle, float player_angle);
int			create_rgb(int r, int g, int b);
void		rgb_to_int(t_game *game);
void		pixel_put(t_game *game, int x, int y, int color);
void		clear_image(t_game *game, int color);

// init.c
void		init_img(t_game *game);
void		init_player(t_game *game);
void		init_raycasting(t_game *game);
void		init_texture(t_game *game, t_texture *t, char *path);
void		init_game(t_game *game);

// hooks.c
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);

// player_utils.c
bool		touch(float px, float py, t_game *game);
void		update_rotation(t_game *game);
void		check_key(t_game *game, float *next_x, float *next_y);
bool		can_move(float next_x, float next_y, t_game *game);
void		update_movement(t_game *game);

// fps.c
long long	get_time_ms(void);
void		calculate_fps(double *fps);
void		draw_fps(t_game *game, double fps);

// ray_casting.c
void		update_raycasting_values(t_game *game, int i);
void		init_step_and_sidedist(t_game *game);
void		perform_dda(t_game *g);
void		ray_casting(t_game *game);
int			handle_close(void *param);

// main.c
int			game_loop(t_game *game);
void		init_struct(t_map *map_info);
void		free_parsing(t_map *map_info);
void		free_exit(char *msg, t_map *map_info, int code);
void		free_gnl(t_map *map_info);
int			main(int argc, char **argv);

// parser.c
int			parser(int argc, char **argv, t_map *map_info);
int			open_map(char *filename, t_map *map_info);
int			parse_file(t_map *map_info);

//parse_textures
int			parse_textures(char *line, t_map *map_info, char **texture_path);
int			open_file(char **texture_path, t_map *map_info);
int			get_len(char *line);
char		*get_texture_path(t_map *map_info, char *line, int len);
int			check_for_more_elements(t_map *map_info, char *line);

//parser_colors.c
int    parse_colors(char *line, t_map *map_info, int rgb[3]);
int get_rgb_value(char **line, t_map *map_info);

#endif