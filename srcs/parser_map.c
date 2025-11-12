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

void	parse_map(t_map *map_info)
{
	read_map(map_info);
	create_ff_matrix(map_info);
	flood_fill(map_info->ff_matrix, map_info, map_info->player_pos[0],
		map_info->player_pos[1]);
	create_int_matrix(map_info);
}

void	flood_fill(char **matrix, t_map *map_info, int x, int y)
{
	if (!matrix[x][y] || matrix[x][y] == '\n' || matrix[x][y] == '\r'
		|| matrix[x][y] == '\0' || matrix[x][y] == 'X' || matrix[x][y] == ' ')
		free_exit("Map is not surrounded by walls.", map_info, 1);
	else if (matrix[x][y] == '1' || matrix[x][y] == 'V')
		return ;
	matrix[x][y] = 'V';
	flood_fill(matrix, map_info, x + 1, y);
	flood_fill(matrix, map_info, x - 1, y);
	flood_fill(matrix, map_info, x, y + 1);
	flood_fill(matrix, map_info, x, y - 1);
}

static void	allocate_int_rows(t_map *map_info)
{
	int	i;

	map_info->map = malloc(sizeof(int *) * (map_info->height));
	if (!map_info->map)
		free_exit("Memory allocation failed for int_matrix.", map_info, 1);
	i = 0;
	while (i < map_info->height)
	{
		map_info->map[i] = ft_calloc(map_info->width, sizeof(int));
		if (!map_info->map[i])
			free_exit("Memory allocation failed.", map_info, 1);
		i++;
	}
}

static void	fill_int_row(t_map *map_info, int row)
{
	int	j;
	int	line_len;

	j = 0;
	line_len = (int)ft_strlen(map_info->char_matrix[row]);
	while (j < map_info->width)
	{
		if (j < (int)ft_strlen(map_info->char_matrix[row]))
		{
			if (ft_strchr("NSEW", map_info->char_matrix[row][j]))
			{
				map_info->player_pos[0] = j;
				map_info->player_pos[1] = row;
			}
			if (map_info->char_matrix[row][j] == '1')
				map_info->map[row][j] = 1;
		}
		else
			map_info->map[row][j] = 0;
		j++;
	}
}

void	create_int_matrix(t_map *map_info)
{
	int	i;

	allocate_int_rows(map_info);
	i = 0;
	while (i < map_info->height)
	{
		fill_int_row(map_info, i);
		i++;
	}
}
