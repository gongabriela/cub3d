/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:26:41 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/09 16:26:41 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    parse_map(t_map *map_info)
{
    int     width;
    int     height;

    read_map(map_info, &width, &height);
    printf("%s", map_info->line);
    free_exit("map parsing not yet implemented", map_info, 1);
}

void    read_map(t_map *map_info, int *width, int *height)
{
    char    *map;

    *height = 1;
	*width	= 0;
    map_info->tmp = get_next_line(map_info->filename_fd);
    while(map_info->tmp)
    {
		calculate_max_width(width, map_info->tmp);
        check_map_line_validity(map_info->tmp, map_info);
        (*height)++;
        map = ft_strjoin(map_info->line, map_info->tmp);
        free(map_info->line);
        free(map_info->tmp);
        map_info->line = map;
        map_info->tmp = get_next_line(map_info->filename_fd);
    }
}

void	calculate_max_width(int	*width, char *curr_line)
{
    int		line_len;

	line_len = ft_strlen(curr_line);
	if (line_len > 0 && curr_line[line_len - 1] == '\n')
		line_len--;
    if (line_len > *width)
            *width = line_len;
}

void    check_map_line_validity(char *line, t_map *map_info)
{
    static int  player_count = 0;
    int     i;

    i = 0;
    while (line[i] == ' ' || line[i] == '\t')
        i++;
    if (line[i] == '\n' || line[i] == '\r' || line[i] == '\0')
        free_exit("Empty line: map bust be the last element of the file", map_info, 1);
    while (line[i])
    {
        if (!ft_strchr(" 01NSEW\n\r", line[i]))
            free_exit("Invalid character in map", map_info, 1);
        if (ft_strchr("NSEW", line[i]))
            player_count++;
        if (player_count > 1)
            free_exit("Multiple player start positions found", map_info, 1);
        i++;
    }
    if (line [i - 1] != '\n' && line[i] == '\0' && player_count == 0)
        free_exit("No player start position found in map", map_info, 1);
}
