/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:26:06 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/07 16:36:48 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	rgb_to_int(t_game *game)
{
	game->c_color = create_rgb(game->map_info.c_rgb[0],
			game->map_info.c_rgb[1], game->map_info.c_rgb[2]);
	game->f_color = create_rgb(game->map_info.f_rgb[0],
			game->map_info.f_rgb[1], game->map_info.f_rgb[2]);
}

void	pixel_put(t_game *game, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= 1280 || y < 0 || y >= 720)
		return ;
	dst = game->img.addr + (y * game->img.line_length
			+ x * (game->img.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	clear_image(t_game *game, int color)
{
	int				i;
	int				total_pixels;
	unsigned int	*pixel;

	i = 0;
	total_pixels = SCREEN_WIDTH * SCREEN_HEIGHT;
	pixel = (unsigned int *) game->img.addr;
	while (i < total_pixels)
	{
		pixel[i] = color;
		i++;
	}
}
