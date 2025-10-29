/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:06:37 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/29 14:31:22 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	update_raycasting_values(t_game *game, int i)
{
	game->r.ray_angle = game->player.angle - (FOV * PI / 180)
		/ 2 + i * game->r.angle_step;
	game->r.posx = game->player.x / BLOCK;
	game->r.posy = game->player.y / BLOCK;
	game->r.raydirx = cos(game->r.ray_angle);
	game->r.raydiry = sin(game->r.ray_angle);
	game->r.mapx = (int)game->r.posx;
	game->r.mapy = (int)game->r.posy;
	game->r.deltadistx = fabs(1 / game->r.raydirx);
	game->r.deltadisty = fabs(1 / game->r.raydiry);
}

void	init_step_and_sidedist(t_game *game)
{
	if (game->r.raydirx < 0)
	{
		game->r.stepx = -1;
		game->r.sidedistx = (game->r.posx - game->r.mapx) * game->r.deltadistx;
	}
	else
	{
		game->r.stepx = 1;
		game->r.sidedistx = (game->r.mapx + 1.0 - game->r.posx)
			* game->r.deltadistx;
	}
	if (game->r.raydiry < 0)
	{
		game->r.stepy = -1;
		game->r.sidedisty = (game->r.posy - game->r.mapy) * game->r.deltadisty;
	}
	else
	{
		game->r.stepy = 1;
		game->r.sidedisty = (game->r.mapy + 1.0 - game->r.posy)
			* game->r.deltadisty;
	}
}

void	perform_dda(t_game *g)
{
	while (1)
	{
		if (g->r.sidedistx < g->r.sidedisty)
		{
			g->r.sidedistx += g->r.deltadistx;
			g->r.mapx += g->r.stepx;
			g->r.side = 0;
		}
		else
		{
			g->r.sidedisty += g->r.deltadisty;
			g->r.mapy += g->r.stepy;
			g->r.side = 1;
		}
		if (g->r.mapx < 0 || g->r.mapy < 0
			|| g->r.mapx >= MAP_WIDTH || g->r.mapy >= MAP_HEIGHT)
			break ;
		if (g->map[g->r.mapy][g->r.mapx] == 1)
			break ;
	}
}

void	ray_casting(t_game *game)
{
	int		i;
	float	dist;

	i = 0;
	while (i < NUM_RAYS)
	{
		update_raycasting_values(game, i);
		init_step_and_sidedist(game);
		perform_dda(game);
		if (game->r.side == 0)
			game->r.distance = (game->r.sidedistx - game->r.deltadistx) * BLOCK;
		else
			game->r.distance = (game->r.sidedisty - game->r.deltadisty) * BLOCK;
		dist = correct_fisheye(game->r.distance, game->r.ray_angle,
				game->player.angle);
		draw_wall_slice_texture(game, i, dist);
		i++;
	}
}
