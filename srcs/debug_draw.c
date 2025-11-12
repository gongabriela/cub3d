/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:24:58 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/12 12:07:06 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_player(t_game *game)
{
	int	size;
	int	y;
	int	x;

	size = 10;
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

void	draw_square(t_game *game, int start_x, int start_y, int color)
{
	int	x;
	int	y;

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

void	draw_map(t_game *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	while (i < game->map_info.height)
	{
		j = 0;
		while (j < game->map_info.width)
		{
			x = j * BLOCK;
			y = i * BLOCK;
			if (game->map_info.map[i][j] == 1)
				draw_square(game, x, y, 0x888888);
			j++;
		}
		i++;
	}
}
