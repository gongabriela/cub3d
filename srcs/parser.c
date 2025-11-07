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

int map[MAP_HEIGHT][MAP_WIDTH] = {
    {0,0,0,1,1,1,1,1,1,1},
    {0,0,1,0,0,0,0,0,0,1},
    {0,1,0,0,0,0,0,0,0,1},
    {1,1,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,1,0,0,1,1,1},
    {1,0,0,0,0,0,0,1,0,0},
    {1,0,0,0,1,1,1,1,0,0},
    {1,0,0,0,1,0,1,1,0,0},
    {1,1,1,1,1,0,1,1,0,0}
};

int	parser(int argc, char **argv, t_map *map_info)
{
	map_info->map = map;
	map_info->player_ori = 'W';
	map_info->player_pos[0] = 4;
	map_info->player_pos[1] = 4;
	map_info->c_rgb[0] = 135;
	map_info->c_rgb[1] = 206;
	map_info->c_rgb[2] = 235;
	map_info->f_rgb[0] = 34;
	map_info->f_rgb[1] = 139;
	map_info->f_rgb[2] = 34;
	if (argc != 2)
		return (printf("Error\nInvalid number of arguments.\n"), 1);
	if (!open_map(argv[1], map_info))
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
		return (printf("Error\nInvalid file extension\n"), 0);
	map_info->filename = filename;
	map_info->filename_fd = open(filename, O_RDONLY);
	if (map_info->filename_fd > 0)
		return (1);
	return (printf("Error\nCould not open file: %s\n", filename), 0);
}

int	parse_file(t_map *map_info)
{
	char	*line;

	line = get_next_line(map_info->filename_fd);
	while (line)
	{

		if (ft_strncmp(line, "NO ", 3) == 0)
			parse_textures(line, map_info, &map_info->n_path);
		else if (ft_strncmp(line, "SO ", 3) == 0)
			parse_textures(line, map_info, &map_info->s_path);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			parse_textures(line, map_info, &map_info->w_path);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			parse_textures(line, map_info, &map_info->e_path);
		free(line);
		line = get_next_line(map_info->filename_fd);
	}
	return (0);
}

//funcao para limpar o gnl se der