/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:13:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/22 15:48:21 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../minilibx/mlx.h"
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <sys/time.h>
#include <stdio.h>

#define	PI 3.14159265358979323846
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define W 119
#define A 97
#define S 115
#define D 100
#define LEFT_ARROW 65361
#define RIGHT_ARROW 65363
#define	ESC 65307
#define SPEED 2
#define ANGLE_SPEED 0.05
#define BLOCK 50
#define FOV 60
#define NUM_RAYS 1280
#define RAY_STEP 1
#define DEBUG 0
#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720
#define PLAYER_RADIUS 10

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
	void		*mlx;
	void		*mlx_win;
	t_img		img;
	t_player	player;
	int (*map)[MAP_WIDTH];
}	t_game;


// init.c
void	init_img(t_game *game);
void 	init_player(t_game *game);
void 	init_game(t_game *game);

// hooks.c
int 	key_press(int keycode, t_game *game);
int	 	key_release(int keycode, t_game *game);
int 	game_loop(t_game *game);

// draw.c
void	pixel_put(t_game *game, int x, int y, int color);
void 	clear_image(t_game *game, int color);
void	draw_player(t_game *game);
void	draw_square(t_game *game, int start_x, int start_y, int color);
void	draw_map(t_game *game);

// draw_2.c
void 	draw_celling_floor(t_game *game);

// ray_casting.c
bool	touch(float px, float py, t_game *game);
void 	ray_casting2D(t_game *game);
void 	ray_casting3D(t_game *game);

// player_utils.c
void update_movement(t_game *game);

// fps.c
long long get_time_ms();
void calculate_fps(double *fps);
void	draw_fps(t_game *game, double fps);


#endif