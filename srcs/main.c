/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:11:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/07 16:15:37 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct(t_map *map_info)
{
	map_info->filename = NULL;
	map_info->filename_fd = -1;
	map_info->n_path = NULL;
	map_info->s_path = NULL;
	map_info->w_path = NULL;
	map_info->e_path = NULL;
}
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
}

void	free_exit(char *msg, t_map *map_info, int code)
{
	if (msg)
    	printf("%s", msg);
	free_parsing(map_info);
	exit(code);
}

int	main(int argc, char **argv)
{
	t_map	map_info;

	init_struct(&map_info);
	if (parser(argc, argv, &map_info))
		free_exit(NULL, &map_info, 1);
	free_parsing(&map_info);
	return (0);
}
