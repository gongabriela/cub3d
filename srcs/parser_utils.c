/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 09:58:22 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/10/08 09:58:22 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	alloc_mem(t_game *game)
{
	game->f_rgb = malloc(4 * sizeof(int));
	game->c_rgb = malloc(4 * sizeof(int));
	ft_memset(game->f_rgb, 0, 4 * sizeof(int));
	ft_memset(game->c_rgb, 0, 4 * sizeof(int));
}

int	is_texture(char *line, int i)
{
	if (ft_strncmp(&line[i], "NO", 2) == 0 || ft_strncmp(&line[i], "SO", 2) == 0
		|| ft_strncmp(&line[i], "WE", 2) == 0 || ft_strncmp(&line[i], "EA", 2) == 0)
		return (1);
	return (0);
}

void	invalid_element_error(t_game *game)
{
	printf("Error\nInvalid element in configuration file.\n");
	game->error = 1;
}
