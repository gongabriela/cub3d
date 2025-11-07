/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:20:36 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/07 16:37:53 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_celling_floor(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT / 2)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			pixel_put(game, x, y, game->c_color);
			x++;
		}
		y++;
	}
	y = SCREEN_HEIGHT / 2;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			pixel_put(game, x, y, game->f_color);
			x++;
		}
		y++;
	}
}

t_texture	*get_correct_texture(t_game *g)
{
	if (g->r.side == 0)
	{
		if (g->r.raydirx > 0)
			return (&g->e);
		else
			return (&g->w);
	}
	else
	{
		if (g->r.raydiry > 0)
			return (&g->s);
		else
			return (&g->n);
	}
}

int	get_tex_x(t_game *g, t_texture *tex)
{
	float	hit;
	int		tx;

	if (g->r.side == 0)
		hit = g->r.posy + g->r.distance / BLOCK * g->r.raydiry;
	else
		hit = g->r.posx + g->r.distance / BLOCK * g->r.raydirx;
	hit -= floor(hit);
	tx = (int)(hit * tex->width);
	if ((g->r.side == 0 && g->r.raydirx < 0)
		|| (g->r.side == 1 && g->r.raydiry > 0))
		tx = tex->width - tx - 1;
	return (tx);
}

void	draw_tex_column(t_game *g, int x, t_slice slice, t_texture *tex)
{
	int		y;
	int		tx;
	int		ty;
	float	step;
	float	pos;

	tx = get_tex_x(g, tex);
	step = (float)tex->height / (float)slice.height;
	pos = (slice.start - SCREEN_HEIGHT / 2 + slice.height / 2) * step;
	y = slice.start;
	while (y <= slice.end)
	{
		ty = (int)pos;
		if (ty >= tex->height)
			ty = tex->height - 1;
		pixel_put(g, x, y,
			tex->data[ty * tex->width + tx]);
		pos += step;
		y++;
	}
}

void	draw_wall_slice_texture(t_game *g, int x, float dist)
{
	t_slice		slice;
	t_texture	*correct_texture;

	if (dist < 0.0001f)
		dist = 0.0001f;
	slice.height = (int)((BLOCK * (SCREEN_WIDTH / 2.0f)
				/ tan((FOV / 2) * PI / 180)) / dist);
	slice.start = (SCREEN_HEIGHT / 2) - (slice.height / 2);
	slice.end = slice.start + slice.height;
	if (slice.start < 0)
		slice.start = 0;
	if (slice.end >= SCREEN_HEIGHT)
		slice.end = SCREEN_HEIGHT - 1;
	correct_texture = get_correct_texture(g);
	draw_tex_column(g, x, slice, correct_texture);
}

float	correct_fisheye(float distance, float ray_angle, float player_angle)
{
	return (distance * cos(ray_angle - player_angle));
}
