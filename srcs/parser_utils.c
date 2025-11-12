/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:55:12 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/12 16:57:32 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*skip_spaces(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

int	is_texture(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0 || ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0 || ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	return (0);
}

void	main_parse_textures(t_map *map_info, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		parse_textures(line, map_info, &map_info->n_path);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		parse_textures(line, map_info, &map_info->s_path);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		parse_textures(line, map_info, &map_info->w_path);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		parse_textures(line, map_info, &map_info->e_path);
}
