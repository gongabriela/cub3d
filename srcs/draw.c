/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:24:58 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/18 19:11:05 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,0,2,0,1,0,1},
    {1,0,1,0,0,0,0,1,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,0,2,0,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,1,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

void pixel_put(t_game *game, int x, int y, int color)
{
	char *dst;
	
	dst = game->img.addr + (y * game->img.line_length + x * (game->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_player(t_game *game)
{
	int size = 25;
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
	while (y < start_y + 50)
	{
		x = start_x;
		while (x < start_x + 50)
		{
			pixel_put(game, x, y, color);
			x++;
		}
		y++;
	}
}

void draw_map(t_game *game)
{
	int square_size = 50;
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
			x = j * square_size;
			y = i * square_size;
			if (map[i][j] == 1)
				draw_square(game, x, y, 0x888888);
			else if (map[i][j] == 2)
				draw_square(game, x, y, 0x00FF00);
			j++;
		}
		i++;
	}
}
