/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:24:58 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/20 15:27:19 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void pixel_put(t_game *game, int x, int y, int color)
{
	char *dst;
	
	if (x < 0 || x >= 1280 || y < 0 || y >= 720)
		return;
	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
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

void	draw_player(t_game *game)
{
	int size = 10;
	int y; 
	int x;

	y = (int)game->player.y - size / 2;
	while (y < (int)game->player.y + size / 2)
	{
		x = (int)game->player.x - size / 2;
		while (x < (int)game->player.x + size / 2)
		{
			pixel_put(game, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

void draw_square(t_game *game, int start_x, int start_y, int color)
{
	int x;
	int y;

	y = start_y;
	while (y < start_y + BLOCK)
	{
		x = start_x;
		while (x < start_x + BLOCK)
		{
			pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
}

void draw_map(t_game *game)
{
	int x;
	int y;
	int i;
	int j;

	i = 0;
	while (i < MAP_HEIGHT)
	{
		j = 0;
		while (j < MAP_WIDTH)
		{
			x = j * BLOCK;
			y = i * BLOCK;
			if (game->map[i][j] == 1)
				draw_square(game, x, y, 0x888888);
			j++;
		}
		i++;
	}
}
