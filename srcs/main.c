/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:11:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/07 18:24:31 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	handle_close(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->mlx_win)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		mlx_destroy_image(game->mlx, game->n.img);
		mlx_destroy_image(game->mlx, game->s.img);
		mlx_destroy_image(game->mlx, game->e.img);
		mlx_destroy_image(game->mlx, game->w.img);
		mlx_destroy_window(game->mlx, game->mlx_win);
	}
	exit(0);
	return (0);
}


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
	map_info->filename = NULL;
	map_info->filename_fd = -1;
	map_info->n_path = NULL;
	map_info->s_path = NULL;
	map_info->w_path = NULL;
	map_info->e_path = NULL;
}
void	free_parsing(t_map *map_info)
{
	if (map_info->filename_fd != -1)
		close(map_info->filename_fd);
	if (map_info->n_path != NULL)
		free(map_info->n_path);
	if (map_info->s_path != NULL)
		free(map_info->s_path);
	if (map_info->w_path != NULL)
		free(map_info->w_path);
	if (map_info->e_path != NULL)
		free(map_info->e_path);
}

void	free_exit(char *msg, t_map *map_info, int code)
{
	if (msg)
    	printf("%s", msg);
	free_parsing(map_info);
	exit(code);
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
