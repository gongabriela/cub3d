/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:17:55 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/22 15:53:56 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

long long get_time_ms()
{
	struct timeval tv;
	long long time_in_ms;

	gettimeofday(&tv, NULL);
	time_in_ms = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return time_in_ms;
}

void calculate_fps(double *fps)
{
	static long long last_time = 0;
	long long current_time;
	double delta;

	current_time = get_time_ms();
	if (last_time != 0)
	{
		delta = (current_time - last_time) / 1000.0; //delta (tempo do frame anterior para atual em segundos
		if (delta > 0)
			*fps = 1 / delta;
	}
	last_time = current_time;
}

void	draw_fps(t_game *game, double fps)
{
	char text[32];

	snprintf(text, sizeof(text), "FPS: %.1f", fps);
	mlx_string_put(game->mlx, game->mlx_win, 10, 20, 0xFFFFFF, text);
}