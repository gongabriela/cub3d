/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:13:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/10/22 13:00:49 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"  // Add this line for libft functions
// Game struct with only used variables
typedef struct s_game
{
	char	*filename;
	int		filename_fd;
	char	**map;
	int		*f_rgb;
	int		*c_rgb;
	int		no_texture;
	int		so_texture;
	int		we_texture;
	int		ea_texture;
	int		error;
}	t_game;

// Function prototypes

// main.c
void	init_struct(t_game *game);
void	free_exit(t_game *game, int code);

// parser.c
int		parser(int argc, char **argv, t_game *game);
int		open_map(char *filename, t_game *game);
void	alloc_mem(t_game *game);
int		parse_file_elements(t_game *game);
int		check_missing_elements(t_game *game);
int		is_texture(char *line, int i);
void	invalid_element_error(t_game *game);

// parser_colors.c
void	parse_colors(char *line, int i, t_game *game);
int		parse_elements(char *line, int i, t_game *game, char type);
int		check_rgb(char *line, int *i);

// parser_textures.c
void	parse_textures(char *line, int i, t_game *game);
int		count_elements(char *line, int i, t_game *game);
int		check_texture_path(char *path, t_game *game, char *type);

// parser_map.c
void	parse_map(t_game *game);

#endif