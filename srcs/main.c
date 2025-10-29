/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:11:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/29 16:02:42 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->mlx_win)
	{
		if (game->img.img)
			mlx_destroy_image(game->mlx, game->img.img);
		if (game->wall_texture.img)
			mlx_destroy_image(game->mlx, game->wall_texture.img);
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	exit(0);
	return (0);
}


int	game_loop(t_game *game)
{
	double	fps;

	fps = 0;
	calculate_fps(&fps);
	clear_image(game, 0x000000);
	draw_celling_floor(game);
	update_movement(game);
	if (DEBUG == 1)
	{
		draw_player(game);
		draw_map(game);
		ray_casting2d(game);
	}
	else
		ray_casting(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img.img, 0, 0);
	draw_fps(game, fps);
	return (0);
}

int	main(void)
{
	t_game	game;

	init_game(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx_win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.mlx_win, 17, 1L << 17, handle_close, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
