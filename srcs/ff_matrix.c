/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:05:14 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/12 14:28:57 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	get_ff_len(t_map *map_info, int row)
{
	if (row == 0)
		return (ft_strlen(map_info->char_matrix[0]) + 2);
	else if (row == map_info->height + 1)
		return (ft_strlen(map_info->char_matrix[map_info->height - 1]) + 2);
	else
		return (ft_strlen(map_info->char_matrix[row - 1]) + 2);
}

void	create_ff_matrix(t_map *map_info)
{
	int	i;
	int	size;
	int	prev_size;

	map_info->ff_matrix = malloc(sizeof(char *) * (map_info->height + 3));
	if (!map_info->ff_matrix)
		free_exit("Memory allocation failed for ff_matrix.", map_info, 1);
	i = 0;
	prev_size = 0;
	while (i < map_info->height + 2)
	{
		size = get_ff_len(map_info, i);
		if (size + 1 < prev_size)
			size = prev_size - 1;
		map_info->ff_matrix[i] = malloc(sizeof(char) * (size + 1));
		if (!map_info->ff_matrix[i])
			free_exit("Memory allocation failed.", map_info, 1);
		fill_ff_matrix_row(map_info, i, size);
		prev_size = (int)ft_strlen(map_info->ff_matrix[i]);
		i++;
	}
	map_info->ff_matrix[i] = NULL;
}

static void	fill_ff_player_pos(t_map *map_info, int row, int i)
{
	map_info->player_pos[0] = row;
	map_info->player_pos[1] = i;
	map_info->player_ori = map_info->ff_matrix[row][i];
	map_info->ff_matrix[row][i] = '0';
}

void	fill_ff_matrix_row(t_map *map_info, int row, int size)
{
	int	i;
	int	char_len;

	i = 0;
	if (row > 0 && row < map_info->height + 1)
		char_len = ft_strlen(map_info->char_matrix[row - 1]);
	else
		char_len = 0;
	while (i < size)
	{
		if (row == 0 || row == map_info->height + 1)
			map_info->ff_matrix[row][i] = 'X';
		else if (i == 0 || i > char_len)
			map_info->ff_matrix[row][i] = 'X';
		else
		{
			map_info->ff_matrix[row][i] = map_info->char_matrix[row - 1][i - 1];
			if (ft_strchr("NSEW", map_info->ff_matrix[row][i]))
				fill_ff_player_pos(map_info, row, i);
		}
		i++;
	}
	if (i == size)
		map_info->ff_matrix[row][i] = '\0';
}
