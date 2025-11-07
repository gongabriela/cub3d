/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:31:24 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/10/06 14:31:24 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parser(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (printf("Error\nInvalid number of arguments.\n"), 1);
	if (!open_map(argv[1], game))
		return (1);
	close(game->filename_fd);
	game->filename_fd = -1;
	return (0);
}

int	open_map(char *filename, t_game *game)
{
	int	len;

	len = strlen(filename);
	if (len < 4 || ft_strucmp(&filename[len - 4], ".cub") != 0)
		return (printf("Error\nInvalid file extension\n"), 0);
	game->filename = filename;
	game->filename_fd = open(filename, O_RDONLY);
	if (game->filename_fd > 0)
		return (1);
	return (printf("Error\nCould not open file: %s\n", filename), 0);
}
