/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:22:21 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/18 18:41:31 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int key_press(int keycode, t_game *game)
{
	if (keycode == 'w')
		game->move.w = true;
	if (keycode == 'a')
		game->move.a = true;
	if (keycode == 's')
		game->move.s = true;
	if (keycode == 'd')
		game->move.d = true;
	return (0);
}

int key_release(int keycode, t_game *game)
{
	if (keycode == 'w')
		game->move.w = false;
	if (keycode == 'a')
		game->move.a = false;
	if (keycode == 's')
		game->move.s = false;
	if (keycode == 'd')
		game->move.d = false;
	return (0);
}

void clear_image(t_game *game, int color)
{
    int i = 0;
    int total_pixels = 1280 * 720;
    unsigned int *pixel = (unsigned int *)game->img.addr;

    while (i < total_pixels)
    {
        pixel[i] = color;
        i++;
    }
}


int game_loop(t_game *game)
{
	clear_image(game, 0x000000);
	if (game->move.w)
		game->player.y -= 0.5;
	if (game->move.s)
		game->player.y += 0.5;
	if (game->move.a)
		game->player.x -= 0.5;
	if (game->move.d)
		game->player.x += 0.5;
	draw_map(game);
	draw_player(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	return (0);	
}