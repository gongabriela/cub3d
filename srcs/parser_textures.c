/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:04:08 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/12 14:22:13 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_textures(char *line, t_map *map_info, char **texture_path)
{
	int	len;

	if (!line)
		return (free_exit("Invalid texture path.", map_info, 1), 1);
	if (*texture_path != NULL)
		return (free_exit("Duplicated texture element.", map_info, 1), 1);
	line += 3;
	while (*line == ' ' || *line == '\t')
		line++;
	if (ft_strncmp(line, "./", 2) != 0)
		return (free_exit("Invalid texture path.", map_info, 1), 1);
	len = get_len(line);
	*texture_path = get_texture_path(map_info, line, len);
	if (!*texture_path)
		return (1);
	if (open_file(texture_path, map_info))
		return (1);
	if (check_for_more_elements(map_info, line + len))
		return (1);
	return (0);
}

int	check_for_more_elements(t_map *map_info, char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line != '\0' && *line != '\n' && *line != '\r')
		return (free_exit("Too many elements @ texture info.", map_info, 1), 1);
	return (0);
}

int	open_file(char **texture_path, t_map *map_info)
{
	int	fd;

	fd = open(*texture_path, O_RDONLY);
	if (fd < 0)
		free_exit("Texture doesn't exist or can't be opened.", map_info, 1);
	close(fd);
	return (0);
}

int	get_len(char *line)
{
	char	*path_end;

	path_end = line;
	while (*path_end && *path_end != ' ' && *path_end != '\n'
		&& *path_end != '\r' && *path_end != '\t')
		path_end++;
	return (path_end - line);
}

char	*get_texture_path(t_map *map_info, char *line, int len)
{
	char	*texture_path;
	char	*tmp;

	if (len == 0)
		return (free_exit("Invalid texture path.", map_info, 1), NULL);
	tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (free_exit("Memory allocation failed.", map_info, 1), NULL);
	ft_memcpy(tmp, line, len);
	tmp[len] = '\0';
	texture_path = ft_strdup(tmp);
	free(tmp);
	if (!texture_path)
		return (free_exit("Memory allocation failed.", map_info, 1), NULL);
	if (len < 4 || ft_strncmp((texture_path + (len - 4)), ".xpm", 4) != 0)
	{
		free(texture_path);
		texture_path = NULL;
		free_exit("Invalid texture file extension. Expected .xpm", map_info, 1);
	}
	return (texture_path);
}
