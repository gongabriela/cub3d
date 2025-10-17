/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:11:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/17 19:44:17 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void img_init(t_game *game, t_img *img)
{
	img->img = mlx_new_image(game->mlx, 1280, 720);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	img->game = game;
}

void pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;
	
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void player_init(t_player *player) 
{
	player->x = 300;
	player->y = 300;
}

void	draw_player(t_img *img, t_player *player, int color)
{
	int size = 50;
	int y; 
	int x;

	y = (int)player->y - size / 2;
	while (y < (int)player->y + size / 2)
	{
		x = (int)player->x - size / 2;
		while (x < (int)player->x + size / 2)
		{
			pixel_put(img, x, y, color);
			x++;
		}
		y++;
	}
	
}

int main (void)
{
	t_game	game;
	t_img	img;
	t_player player;

	player_init(&player);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1280, 720, "cub3d");
	img_init(&game, &img);
	draw_player(&img, &player, 0x00FF0000);
	mlx_put_image_to_window(game.mlx, game.mlx_win, img.img, 0, 0);
	mlx_loop(game.mlx);

	return (0);
}