/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:35:19 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/10/08 12:35:19 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_map(char *line, int i, t_game *game)
{
	(void)game;
	game->map = copy_map(game);
	game->ff_map = duplicate_map(game->map);
	if (game->error != 0)
	{
		print_error_msg(game);
		return ;
	}
	flood_fill(game, game->player_x, game->player_y);
	if (game->error != 0)
		print_error_msg(game);
}

char	**copy_map(char *line, int i, t_game *game)
{
	while (line)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '\n' || line[i] == '\0' && game->error == 0)
			game->error = 6; // Empty line in map
		while (line[i] != \n)
			i++;
		if (game->error == 0 && line[i + 1] == '\n')
			game->error = 6; // Empty line in map
	}
}

void	print_error_msg(t_game *game)
{
	if (game->error == 1)
		printf("Error\nMap is not surrounded by walls\n");
	if (game->error == 2)
		printf("Error\nMissing player start position\n");
	if (game->error == 3)
		printf("Error\nMultiple player start positions\n");
	if (game->error == 4)
		printf("Error\nInvalid player start position direction\n");
	if (game->error == 5)
		printf("Error\nInvalid character in map\n");
	if (game->error == 6)
		printf("Error\nEmpty line in map\n");
	game->error = 1;
}