/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:19:43 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/29 13:36:40 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ray_casting2d(t_game *game)
{
	float	ray_angle;
	float	ray_x;
	float	ray_y;
	float	angle_step;
	int		i;

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
