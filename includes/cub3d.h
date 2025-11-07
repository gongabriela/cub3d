/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:13:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/07 16:15:23 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct s_map
{
	char	*filename;
	int		filename_fd;

	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;

	int		*f_rgb[3];
	int		*c_rgb[3];

	int		**map;

	//posicao x,y do jogador int **, substituir por zero 
	//orientacao da posicao do jogador char *

}	t_map;

// main.c
void	init_struct(t_map *map_info);
void	free_parsing(t_map *map_info);
void	free_exit(char *msg, t_map *map_info, int code);

// parser.c
int		parser(int argc, char **argv, t_map *map_info);
int		open_map(char *filename, t_map *map_info);
int		parse_file(t_map *map_info);

//parse_textures
int		parse_textures(char *line, void *map_info, char **texture_path);
int		open_file(char **texture_path);
int     get_len(char *line);
char    *get_texture_path(t_map *map_info, char *line, int len);

#endif