/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:44:13 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/07 15:47:05 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int map[MAP_HEIGHT][MAP_WIDTH] = {
//     {1,1,1,1,1,1,1,1,1,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,1,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,1,1,1,1,1,1,1,1,1}
// };

void	init_img(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, 1280, 720);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
}

void	init_player(t_game *game)
{
	game->player.x = 3.5 * BLOCK;
	game->player.y = 3.5 * BLOCK;
	game->player.angle = PI / 2;
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.key_left = false;
	game->player.key_right = false;
	game->player.left_rotate = false;
	game->player.right_rotate = false;
}

void	init_raycasting(t_game *game)
{
	game->r.angle_step = (FOV * PI / 180) / NUM_RAYS;
	game->r.ray_angle = 0;
	game->r.posx = 0;
	game->r.posy = 0;
	game->r.raydirx = 0;
	game->r.raydiry = 0;
	game->r.mapx = 0;
	game->r.mapy = 0;
	game->r.deltadistx = 0;
	game->r.deltadisty = 0;
	game->r.sidedistx = 0;
	game->r.sidedisty = 0;
	game->r.stepx = 0;
	game->r.stepy = 0;
	game->r.side = 0;
	game->r.distance = 0;
}

void init_texture(t_game *game, t_texture *t, char *path)
{
	t->img = mlx_xpm_file_to_image(game->mlx, path,  &t->width, &t->height);
	t->data = (int *)mlx_get_data_addr(t->img, &t->bits_per_pixel, &t->line_length, &t->endian);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1280, 720, "cub3d");
	init_img(game);
	init_player(game);
	init_raycasting(game);
	init_texture(game, &game->n, game->map_info.n_path);
	init_texture(game, &game->s, game->map_info.s_path);
	init_texture(game, &game->e ,game->map_info.e_path);
	init_texture(game, &game->w, game->map_info.w_path);
}
