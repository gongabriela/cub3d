/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:12:19 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/12 14:12:39 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_parsing(t_map *map_info)
{
	if (map_info->filename_fd != -1)
		close(map_info->filename_fd);
	if (map_info->n_path != NULL)
		free(map_info->n_path);
	if (map_info->s_path != NULL)
		free(map_info->s_path);
	if (map_info->w_path != NULL)
		free(map_info->w_path);
	if (map_info->e_path != NULL)
		free(map_info->e_path);
	if (map_info->line != NULL)
		free(map_info->line);
	if (map_info->tmp != NULL)
		free(map_info->tmp);
	if (map_info->char_matrix != NULL)
		free_matrix((void **)map_info->char_matrix);
	if (map_info->ff_matrix != NULL)
		free_matrix((void **)map_info->ff_matrix);
	if (map_info->map != NULL)
		free_matrix_int(map_info);
}

void	free_gnl(t_map *map_info)
{
	char	*line;

	line = get_next_line(map_info->filename_fd);
	while (line)
	{
		free(line);
		line = get_next_line(map_info->filename_fd);
	}
}

void	free_matrix(void **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_matrix_int(t_map *map)
{
	int	i;

	if (!map->map)
		return ;
	i = 0;
	while (i < (map->height))
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
}

void	free_exit(char *msg, t_map *map_info, int code)
{
	if (msg)
		printf("Error\n%s\n", msg);
	free_gnl(map_info);
	free_parsing(map_info);
	exit(code);
}
