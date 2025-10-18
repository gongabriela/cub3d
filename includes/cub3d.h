/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:13:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/18 19:11:04 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "../minilibx/mlx.h"
#include <stdbool.h>


#define MAP_WIDTH 10
#define MAP_HEIGHT 10



typedef struct s_move 
{
	bool	w;
	bool	a;
	bool	s;
	bool	d;
	bool	left;
	bool	right;
}	t_move;

typedef struct s_player
{
	double	x;
	double	y;
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
	t_move		move;
}	t_game;


// init.c
void	init_img(t_game *game);
void 	init_player(t_game *game);
void	init_move(t_game *game);
void 	init_game(t_game *game);

// hooks.c
int 	key_press(int keycode, t_game *game);
int	 	key_release(int keycode, t_game *game);
int 	game_loop(t_game *game);

// draw.c
void	pixel_put(t_game *game, int x, int y, int color);
void	draw_player(t_game *game);
void	draw_square(t_game *game, int start_x, int start_y, int color);
void	draw_map(t_game *game);

// render.c




#endif