/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:06:37 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/27 16:01:56 by jpedro-f         ###   ########.fr       */
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

void draw_wall_slice_texture(t_game *game, int ray_id, float distance)
{
    int slice_height;
    int start_y;
    int end_y;
    int y;
    float proj_plane;

    if (distance < 0.0001f)
        distance = 0.0001f;

    proj_plane = (SCREEN_WIDTH / 2.0f) / tan((FOV / 2) * PI / 180);
    slice_height = (int)(BLOCK * proj_plane / distance);

    start_y = (SCREEN_HEIGHT / 2) - (slice_height / 2);
    end_y = start_y + slice_height;

    if (start_y < 0)
        start_y = 0;
    if (end_y >= SCREEN_HEIGHT)
        end_y = SCREEN_HEIGHT - 1;

    // Calculate the exact position on the wall hit
    float wallX;
    if (game->raycasting.side == 0)
        wallX = game->player.y + distance * sin(game->raycasting.ray_angle);
    else
        wallX = game->player.x + distance * cos(game->raycasting.ray_angle);
    wallX -= floor(wallX); // only fractional part

    int texX = (int)(wallX * game->wall_texture.width);
    if ((game->raycasting.side == 0 && game->raycasting.rayDirX > 0) ||
        (game->raycasting.side == 1 && game->raycasting.rayDirY < 0))
        texX = game->wall_texture.width - texX - 1;

    for (y = start_y; y <= end_y; y++)
    {
        int d = (y - (SCREEN_HEIGHT / 2) + (slice_height / 2)) * 256;
        int texY = ((d * game->wall_texture.height) / slice_height) / 256;
        int color = game->wall_texture.data[texY * game->wall_texture.width + texX];
        pixel_put(game, ray_id, y, color);
    }
}


// void draw_wall_slice(t_game *game, int ray_id, float distance)
// {
//     int slice_height;
//     int start_y;
//     int end_y;
//     int y;
//     float proj_plane;

//     if (distance < 0.0001f)
//         distance = 0.0001f;

//     proj_plane = (SCREEN_WIDTH / 2.0f) / tan((FOV / 2) * PI / 180);
//     slice_height = (int)(BLOCK * proj_plane / distance); // basic height

//     start_y = (SCREEN_HEIGHT / 2) - (slice_height / 2);
//     end_y = start_y + slice_height;

//     if (start_y < 0)
//         start_y = 0;
//     if (end_y >= SCREEN_HEIGHT)
//         end_y = SCREEN_HEIGHT - 1;

//     for (y = start_y; y <= end_y; y++)
//         pixel_put(game, ray_id, y, 0x888888);
// }

float correct_fisheye(float distance, float ray_angle, float player_angle)
{
    return distance * cos(ray_angle - player_angle);
}


void update_raycasting_values(t_game *game, int i)
{
	game->raycasting.ray_angle = game->player.angle - (FOV * PI / 180) / 2 + i * game->raycasting.angle_step;
	game->raycasting.posX = game->player.x / BLOCK;
	game->raycasting.posY = game->player.y / BLOCK;
	game->raycasting.rayDirX = cos(game->raycasting.ray_angle);
	game->raycasting.rayDirY = sin(game->raycasting.ray_angle);
	game->raycasting.mapX = (int)game->raycasting.posX;
	game->raycasting.mapY = (int)game->raycasting.posY;
	game->raycasting.deltaDistX = fabs(1 / game->raycasting.rayDirX);
	game->raycasting.deltaDistY = fabs(1 / game->raycasting.rayDirY);
}

void init_step_and_sideDist(t_game *game)
{
	if (game->raycasting.rayDirX < 0)
	{
		game->raycasting.stepX = -1;
		game->raycasting.sideDistX = (game->raycasting.posX - game->raycasting.mapX) * game->raycasting.deltaDistX;
	}
	else
	{
		game->raycasting.stepX = 1;
		game->raycasting.sideDistX = (game->raycasting.mapX + 1.0 - game->raycasting.posX) * game->raycasting.deltaDistX;
	}
	if (game->raycasting.rayDirY < 0)
	{
		game->raycasting.stepY = -1;
		game->raycasting.sideDistY = (game->raycasting.posY - game->raycasting.mapY) * game->raycasting.deltaDistY;
	}
	else
	{
		game->raycasting.stepY = 1;
		game->raycasting.sideDistY = (game->raycasting.mapY + 1.0 - game->raycasting.posY) * game->raycasting.deltaDistY;
	}
}

void ray_casting(t_game *game)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		update_raycasting_values(game, i);
		init_step_and_sideDist(game);
		while (1)
		{
			if (game->raycasting.sideDistX < game->raycasting.sideDistY)
			{
				game->raycasting.sideDistX += game->raycasting.deltaDistX;
				game->raycasting.mapX += game->raycasting.stepX;
				game->raycasting.side = 0;
			}
			else
			{
				game->raycasting.sideDistY += game->raycasting.deltaDistY;
				game->raycasting.mapY += game->raycasting.stepY;
				game->raycasting.side = 1;
			}
			if (game->raycasting.mapX < 0 || game->raycasting.mapY < 0 
				|| game->raycasting.mapY >= MAP_HEIGHT || game->raycasting.mapX >= MAP_WIDTH)
				break;
			if (game->map[game->raycasting.mapY][game->raycasting.mapX] == 1)
				break;
		}
		if (game->raycasting.side == 0)
			game->raycasting.distance = (game->raycasting.sideDistX - game->raycasting.deltaDistX) * BLOCK;
		else
			game->raycasting.distance = (game->raycasting.sideDistY - game->raycasting.deltaDistY) * BLOCK;
		draw_wall_slice_texture(game, i, correct_fisheye(game->raycasting.distance, game->raycasting.ray_angle, game->player.angle));
		i++;
	}
}
