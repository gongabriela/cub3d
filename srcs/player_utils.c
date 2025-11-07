/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:03:26 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/07 17:24:00 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool	touch(float px, float py, t_game *game)
{
	int	grid_x;
	int	grid_y;

	grid_x = (int)px / BLOCK;
	grid_y = (int)py / BLOCK;
	if (grid_x < 0 || grid_x >= MAP_WIDTH || grid_y < 0 || grid_y >= MAP_HEIGHT)
		return (true);
	if (game->map_info.map[grid_y][grid_x] == 1)
		return (true);
	return (false);
}

void	update_rotation(t_game *game)
{
	if (game->player.left_rotate)
		game->player.angle -= ANGLE_SPEED;
	if (game->player.right_rotate)
		game->player.angle += ANGLE_SPEED;
	if (game->player.angle > 2 * PI)
		game->player.angle = 0;
	if (game->player.angle < 0)
		game->player.angle = 2 * PI;
}

void	check_key(t_game *game, float *next_x, float *next_y)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(game->player.angle);
	sin_angle = sin(game->player.angle);
	if (game->player.key_up)
	{
		*next_x += cos_angle * SPEED;
		*next_y += sin_angle * SPEED;
	}
	if (game->player.key_down)
	{
		*next_x -= cos_angle * SPEED;
		*next_y -= sin_angle * SPEED;
	}
	if (game->player.key_right)
	{
		*next_x -= sin_angle * SPEED;
		*next_y += cos_angle * SPEED;
	}
	if (game->player.key_left)
	{
		*next_x += sin_angle * SPEED;
		*next_y -= cos_angle * SPEED;
	}
}

bool	can_move(float next_x, float next_y, t_game *game)
{
	if (touch(next_x - PLAYER_RADIUS, next_y - PLAYER_RADIUS, game))
		return (false);
	if (touch(next_x + PLAYER_RADIUS, next_y + PLAYER_RADIUS, game))
		return (false);
	if (touch(next_x - PLAYER_RADIUS, next_y + PLAYER_RADIUS, game))
		return (false);
	if (touch(next_x + PLAYER_RADIUS, next_y - PLAYER_RADIUS, game))
		return (false);
	return (true);
}

void	update_movement(t_game *game)
{
	float	next_x;
	float	next_y;

	next_x = game->player.x;
	next_y = game->player.y;
	check_key(game, &next_x, &next_y);
	if (can_move(next_x, game->player.y, game))
		game->player.x = next_x;
	if (can_move(game->player.x, next_y, game))
		game->player.y = next_y;
	update_rotation(game);
}
