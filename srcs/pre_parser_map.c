/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_parser_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:50:16 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/11 12:14:54 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//read_map
    //le o mapa ate o fim e guarda numa string.
    //calcula height e width
    //verifica se ha caracteres irregulares ou multiplos/nenhum jogador
void    read_map(t_map *map_info)
{
    char    *map;

    map_info->height = 1;
    map_info->width = 0;
    calculate_max_width(&map_info->width, map_info->line);
    map_info->tmp = get_next_line(map_info->filename_fd);
    while(map_info->tmp)
    {
        calculate_max_width(&map_info->width, map_info->tmp);
        check_map_line_validity(map_info->tmp, map_info);
        map_info-> height++;
        map = ft_strjoin(map_info->line, map_info->tmp);
        free(map_info->line);
        free(map_info->tmp);
        map_info->line = map;
        map_info->tmp = get_next_line(map_info->filename_fd);
    }
    map_info->char_matrix = ft_split(map_info->line, '\n');
    if (!map_info->char_matrix)
        free_exit("Memory allocation failed for char_matrix.", map_info, 1);
    free(map_info->line);
    map_info->line = NULL;
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
void    check_map_line_validity(char *line, t_map *map_info)
{
    static int  player_count = 0;
    int     i;

    i = 0;
    while (line[i] == ' ')
        i++;
    if (line[i] == '\n' || line[i] == '\r' || line[i] == '\0')
        free_exit("map cannot contain empty lines\nmap needs to be the last element of the file", map_info, 1);
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
    if (line[i] == '\0')
    {
        if (player_count == 0)
            free_exit("No player start position found in map", map_info, 1);
    }
}

