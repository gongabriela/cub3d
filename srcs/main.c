/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:11:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/12 14:13:33 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	game_loop(t_game *game)
{
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
	return (0);
}

void	init_struct(t_map *map_info)
{
	int	i;

	i = 0;
	map_info->filename = NULL;
	map_info->filename_fd = -1;
	map_info->n_path = NULL;
	map_info->s_path = NULL;
	map_info->w_path = NULL;
	map_info->e_path = NULL;
	map_info->line = NULL;
	while (i < 3)
	{
		map_info->f_rgb[i] = -1;
		map_info->c_rgb[i] = -1;
		i++;
	}
	map_info->tmp = NULL;
	map_info->char_matrix = NULL;
	map_info->ff_matrix = NULL;
	map_info->map = NULL;
	map_info->width = 0;
	map_info->height = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map_info;

	init_struct(&map_info);
	if (parser(argc, argv, &map_info))
		free_exit(NULL, &map_info, 1);
	game.map_info = map_info;
	init_game(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_press, &game);
	mlx_hook(game.mlx_win, 3, 1L << 1, key_release, &game);
	mlx_hook(game.mlx_win, 17, 1L << 17, handle_close, &game);
	mlx_loop_hook(game.mlx, game_loop, &game);
	mlx_loop(game.mlx);
	free_parsing(&map_info);
	return (0);
}
