/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:11:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/08 17:53:05 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_game *game)
{
	game->filename = NULL;
	game->map = NULL;
	game->filename_fd = -1;
	game->f_rgb = NULL;
	game->c_rgb = NULL;
	game->no_texture = -1;
	game->so_texture = -1;
	game->we_texture = -1;
	game->ea_texture = -1;
}

void	free_exit(t_game *game, int code)
{
	if (game->filename_fd != -1)
		close(game->filename_fd);
	if (game->f_rgb)
		free(game->f_rgb);
	if (game->c_rgb)
		free(game->c_rgb);
	if (game->no_texture)
		close(game->no_texture);
	if (game->so_texture)
		close(game->so_texture);
	if (game->we_texture)
		close(game->we_texture);
	if (game->ea_texture)
		close(game->ea_texture);
	exit(code);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_struct(&game);
	if (parser(argc, argv, &game))
		free_exit(&game, 1);
	return (0);
}
