/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:22:21 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/29 15:51:28 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	key_press(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = true;
	if (keycode == A)
		game->player.key_left = true;
	if (keycode == S)
		game->player.key_down = true;
	if (keycode == D)
		game->player.key_right = true;
	if (keycode == LEFT_ARROW)
		game->player.left_rotate = true;
	if (keycode == RIGHT_ARROW)
		game->player.right_rotate = true;
	if (keycode == ESC)
		handle_close(game);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == W)
		game->player.key_up = false;
	if (keycode == A)
		game->player.key_left = false;
	if (keycode == S)
		game->player.key_down = false;
	if (keycode == D)
		game->player.key_right = false;
	if (keycode == LEFT_ARROW)
		game->player.left_rotate = false;
	if (keycode == RIGHT_ARROW)
		game->player.right_rotate = false;
	return (0);
}
