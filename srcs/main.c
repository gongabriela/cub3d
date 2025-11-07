/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:11:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/07 11:39:49 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_game *game)
{
	game->filename = NULL;
	game->filename_fd = -1;
}

void	free_exit(t_game *game, int code)
{
	if (game->filename_fd != -1)
		close(game->filename_fd);
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
