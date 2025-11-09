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

    *width = ft_strlen(map_info->line);
    *height = 1;
    map_info->tmp = get_next_line(map_info->filename_fd);
    while(map_info->tmp)
    {
        check_map_line_validity(map_info->tmp, map_info);
        (*height)++;
        if ((int)ft_strlen(map_info->tmp) > *width)
            *width = ft_strlen(map_info->tmp);
        map = ft_strjoin(map_info->line, map_info->tmp);
        free(map_info->line);
        free(map_info->tmp);
        map_info->line = map;
        map_info->tmp = get_next_line(map_info->filename_fd);
    }
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

/*char    **split_map_lines(char *map_str, int *width, int *height)
{
    char    **matrix;
    int     i;

    matrix = (char **)malloc(sizeof(char *) * (height + 1));
    if (!matrix)
        return (free_exit("Memory allocation failed", map_info, 1), NULL);
    i = 0;
    while (i < *height)
    {
        matrix[i] = get_matrix_line(&map_str, *width);
        
    }

}

char    *get_matrix_line(char **map_str, int width)
{
    char    *line;
    int     i;

    line = malloc(sizeof(char) * (width + 1));
    if (!line)
        return (NULL);
    i = 0;
    while (*map_str && **map_str != '\n' || **map_str != '\r')
        i++;
    ft_strlcpy(line, *map_str, i);
    if ( *map_str)
        *map_str += i + 1; // Skip newline character
    if (i < width)
    {
        while (i < width)
        {
            line[i] = ' ';
            i++;
        }
    }
    line[i] = '\0';

}*/