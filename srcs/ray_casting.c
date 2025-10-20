/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:06:37 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/20 16:59:53 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

bool touch(float px, float py, t_game *game)
{
	int grid_x = (int)px / BLOCK;
	int grid_y = (int)py / BLOCK;

	if (grid_x < 0 || grid_x >= MAP_WIDTH || grid_y < 0 || grid_y >= MAP_HEIGHT)
		return true;
	if (game->map[grid_y][grid_x] == 1)
		return true;
	return false;
}

void ray_casting2D(t_game *game)
{
	float	ray_angle;
	float	ray_x;
	float	ray_y;
	float	angle_step;
	int i;

	angle_step = (FOV * PI / 180) / NUM_RAYS;
	i = 0;
	while (i < NUM_RAYS)
	{
		ray_angle = game->player.angle - (FOV * PI / 180) / 2 + i * angle_step;
		ray_x = game->player.x;
		ray_y = game->player.y;
		while (!touch(ray_x, ray_y, game))
		{
			pixel_put(game, (int)ray_x, (int)ray_y, 0xFF0000);
			ray_x += cos(ray_angle) * RAY_STEP;
			ray_y += sin(ray_angle) * RAY_STEP;
		}
		i++;
	}
}

void	draw_wall_slice(t_game *game, int ray_id, float distance)
{
	float	proj_plane;
	float	slice_height;
	int		start_y;
	int		end_y;
	int		y;

	proj_plane = (SCREEN_WIDTH / 2) / tan((FOV / 2) * PI / 180);
	slice_height = (BLOCK * proj_plane) / distance;
	start_y = (SCREEN_HEIGHT / 2) - (slice_height / 2);
	end_y = start_y + slice_height;
	y = start_y;
	while (y < end_y)
	{
		pixel_put(game, ray_id, y, 0x888888);
		y++;
	}	
}



float fisheye_fix(t_game *game, float ray_angle, float ray_x, float ray_y) 
{
	float dx;
	float dy;
	float dist;

	dx = ray_x - game->player.x;
	dy = ray_y - game->player.y;
	dist = sqrt(dx * dx + dy * dy);
	dist *= cos(ray_angle - game->player.angle);
	return (dist);
}

void ray_casting3D(t_game *game)
{
	float	ray_angle;
	float	ray_x;
	float	ray_y;
	float	angle_step;
	int i;

	angle_step = (FOV * PI / 180) / NUM_RAYS;
	i = 0;
	while (i < NUM_RAYS)
	{
		ray_angle = game->player.angle - (FOV * PI / 180) / 2 + i * angle_step;
		ray_x = game->player.x;
		ray_y = game->player.y;
		while (!touch(ray_x, ray_y, game))
		{
			ray_x += cos(ray_angle) * RAY_STEP;
			ray_y += sin(ray_angle) * RAY_STEP;
		}
		draw_wall_slice(game, i, fisheye_fix(game, ray_angle, ray_x, ray_y));
		i++;
	}
}

