/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 15:29:58 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/06 18:40:14 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int map[MAP_HEIGHT][MAP_WIDTH] = {
//     {1,1,1,1,1,1,1,1,1,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,1,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,0,0,0,0,0,0,0,0,1},
//     {1,1,1,1,1,1,1,1,1,1}
// };

void init_map(t_map *map) // delete
{
	// map->map = map;
	map->n_path = "textures/n.xpm";
	map->s_path = "textures/s.xpm";
	map->e_path = "textures/e.xpm";
	map->w_path = "textures/w.xpm";
	map->c_rgb[0] = 225;
	map->c_rgb[1] = 30;
	map->c_rgb[2] = 0;
	map->f_rgb[0] = 210;
	map->f_rgb[1] = 100;
	map->f_rgb[2] = 0;
}

void init_texture(t_game *game, t_texture *t, char *path)
{
	t->img = mlx_xpm_file_to_image(game->mlx, path,  &t->width, &t->height);
	t->data = (int *)mlx_get_data_addr(t->img, &t->bits_per_pixel, &t->line_length, &t->endian);
}
