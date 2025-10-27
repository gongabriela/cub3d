/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:44:13 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/27 16:05:15 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

void init_img(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, 1280, 720);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bits_per_pixel, &game->img.line_length, &game->img.endian);
}

void init_player(t_game *game) 
{
	game->player.x = 3.5 * BLOCK;
	game->player.y = 3.5 * BLOCK;
	game->player.angle = PI / 2;
	game->player.key_up = false;
	game->player.key_down = false;
	game->player.key_left = false;
	game->player.key_right = false;
	game->player.left_rotate = false;
	game->player.right_rotate= false;
}

void init_raycasting(t_game *game)
{
	game->raycasting.angle_step = (FOV * PI / 180) / NUM_RAYS;
	game->raycasting.ray_angle = 0;
	game->raycasting.posX = 0;
	game->raycasting.posY = 0;
	game->raycasting.rayDirX = 0;
	game->raycasting.rayDirY = 0;
	game->raycasting.mapX = 0;
	game->raycasting.mapY = 0;
	game->raycasting.deltaDistX = 0;
	game->raycasting.deltaDistY = 0;
	game->raycasting.sideDistX = 0;
	game->raycasting.sideDistY = 0;
	game->raycasting.stepX = 0;
	game->raycasting.stepY = 0;
	game->raycasting.side = 0;
	game->raycasting.distance = 0;
}

void load_wall_texture(t_game *game)
{
	int width;
	int height;
	char *path = "textures/wall.xpm";

	width = 0;
	height = 0;
	game->wall_texture.img = mlx_xpm_file_to_image(game->mlx, path, &width, &height);
	game->wall_texture.data = (int *)mlx_get_data_addr(game->wall_texture.img, &game->wall_texture.bits_per_pixel, &game->wall_texture.line_lenght, &game->wall_texture.endian);
	game->wall_texture.height = height;
	game->wall_texture.width = width;
}

void init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 1280, 720, "cub3d");
	init_img(game);
	init_player(game);
	load_wall_texture(game);
	init_raycasting(game);
	game->map = map;
}