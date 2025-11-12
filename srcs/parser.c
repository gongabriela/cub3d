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

int	parser(int argc, char **argv, t_map *map_info)
{
	if (argc != 2)
		return (free_exit("Invalid number of arguments.", map_info, 1), 1);
	if (open_map(argv[1], map_info))
		return (1);
	if (parse_file(map_info))
		return (1);
	close(map_info->filename_fd);
	map_info->filename_fd = -1;
	return (0);
}

int	open_map(char *filename, t_map *map_info)
{
	int	len;

	len = strlen(filename);
	if (len < 4 || ft_strcmp(&filename[len - 4], ".cub") != 0)
		return (free_exit("Invalid file extension", map_info, 1), 1);
	map_info->filename = filename;
	map_info->filename_fd = open(filename, O_RDONLY);
	if (map_info->filename_fd > 0)
		return (0);
	return (free_exit("Could not open file.", map_info, 1), 1);
}

int	parse_file(t_map *map_info)
{
	map_info->line = get_next_line(map_info->filename_fd);
	while (map_info->line)
	{
		if (ft_strncmp(map_info->line, "NO ", 3) == 0)
			parse_textures(map_info->line, map_info, &map_info->n_path);
		else if (ft_strncmp(map_info->line, "SO ", 3) == 0)
			parse_textures(map_info->line, map_info, &map_info->s_path);
		else if (ft_strncmp(map_info->line, "WE ", 3) == 0)
			parse_textures(map_info->line, map_info, &map_info->w_path);
		else if (ft_strncmp(map_info->line, "EA ", 3) == 0)
			parse_textures(map_info->line, map_info, &map_info->e_path);
		else if (ft_strncmp(map_info->line, "F ", 2) == 0)
			parse_colors(map_info->line, map_info, map_info->f_rgb);
		else if (ft_strncmp(map_info->line, "C ", 2) == 0)
			parse_colors(map_info->line, map_info, map_info->c_rgb);
		else if (is_map_line(map_info->line))
		{
			parse_map(map_info);
			break ;
		}
		free(map_info->line);
		map_info->line = get_next_line(map_info->filename_fd);
	}
	check_missing_elements(map_info);
	return (0);
}

int	is_map_line(char *line)
{
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line == '0' || *line == '1' || *line == 'N' ||
		*line == 'S' || *line == 'E' || *line == 'W')
		return (1);
	return (0);
}

void	check_missing_elements(t_map *map_info)
{
	if (map_info->n_path == NULL || map_info->s_path == NULL ||
		map_info->w_path == NULL || map_info->e_path == NULL)
		free_exit("Missing texture path(s).", map_info, 1);
	if (map_info->f_rgb[0] == -1 || map_info->f_rgb[1] == -1 ||
		map_info->f_rgb[2] == -1 || map_info->c_rgb[0] == -1 ||
		map_info->c_rgb[1] == -1 || map_info->c_rgb[2] == -1)
		free_exit("Missing color value(s).", map_info, 1);
}