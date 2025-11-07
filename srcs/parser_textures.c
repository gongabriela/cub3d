/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:35:05 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/10/08 12:35:05 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_textures(char **line, t_game *game, char **texture_path)
{
	if (*texture_path != NULL)
	{
		printf("Error\nDuplicated texture element.\n");
		return ;
	}
	*line += 3;
	while (**line == ' ')
		(*line)++;
	if(!line || ft_strncmp(*line, "./", 2) != 0)
	{
		printf("Error\nInvalid texture path.\n");
		return ;
	}
	//ver se a extensao acaba em xpm
	//ver se o ficheiro existe e da para abrir
	*texture_path = ft_strdup(*line);
	//ver se tem mais elementos na linha depois do path
}

int	check_texture_path(char *path, t_game *game, char *type)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	if (!ft_strncmp(type, "NO", 2))
		game->no_texture = fd;
	else if (!ft_strncmp(type, "SO", 2))
		game->so_texture = fd;
	else if (!ft_strncmp(type, "EA", 2))
		game->ea_texture = fd;
	else if (!ft_strncmp(type, "WE", 2))
		game->we_texture = fd;
	return (0);
}
