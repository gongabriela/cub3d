/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:26:06 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/29 13:55:54 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
