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
    printf("\nWidth: %d\nHeight: %d\n", width, height);
    free_exit("map parsing not yet implemented", map_info, 1);
}

//reads until the end of the file
//saves it as a single string
//calculates the max width and skips \n character if exists
void    read_map(t_map *map_info, int *width, int *height)
{
    char    *map;

    *height = 1;
    *width = 0;
	calculate_max_width(width, map_info->line);
    check_first_last_line(map_info->line, map_info);
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
//calculate the size of the current line
//checks if it is bigger than width, and if yes, updates width value
void	calculate_max_width(int	*width, char *curr_line)
{
    int		line_len;

	line_len = ft_strlen(curr_line);
	if (line_len > 0 && (curr_line[line_len - 1] == '\n' || curr_line[line_len -1] == '\r'))
		line_len--;
    if (line_len > *width)
            *width = line_len;
}

//pre-parses the map by checking invalid chars
//checks if the player exists and/or if it is duplicated
//checks if the map is the last thing on the file
//melhorar validacao? diferenciar entre empty line no meio do mapa, ou quando o mapa acabou e tem mais coisa....
void    check_map_line_validity(char *line, t_map *map_info)
{
    static int  player_count = 0;
    int     i;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (line[i] == '\n' || line[i] == '\r' || line[i] == '\0')
        free_exit("Empty line in map", map_info, 1);
    if (line[i] != '1') //quando tem tabs ou outros caracteres nao e uma mensagem muito explicita
        free_exit("Map is not surrounded by walls", map_info, 1);
    while (line[i] && line[i] != '\n' && line[i] != '\r')
    {
        if (!ft_strchr(" 01NSEW", line[i]))
            free_exit("Invalid character in map", map_info, 1);
        if (ft_strchr("NSEW", line[i]))
            player_count++;
        if (player_count > 1)
            free_exit("Multiple player start positions found", map_info, 1);
        i++;
    }
    if (line[i - 1] != '1') //melhorar essa msg
        free_exit("Map is not surrounded by walls", map_info, 1);
    if (line[i] == '\0') //se tiver uma newline vazia ele nao chega aqui
    {
        check_first_last_line(line, map_info);
        if (player_count == 0)
            free_exit("No player start position found in map", map_info, 1);
    }
}

//checks if the first and last lines ONLY have walls
void    check_first_last_line(char *line, t_map *map_info)
{
    int i;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (line[i] == '\n' || line[i] == '\r' || line[i] == '\0')
        free_exit("Empty line in map", map_info, 1);
    while (line[i] && line[i] != '\n' && line[i] != '\r')
    {
        if (line[i] != '1') //quando tem tabs ou outros caracteres nao e uma mensagem muito explicita
            free_exit("Map is not surrounded by walls", map_info, 1);
        i++;
    }
}
