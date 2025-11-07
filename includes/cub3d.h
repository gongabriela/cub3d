/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:13:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/11/07 11:38:41 by ggoncalv         ###   ########.fr       */
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

typedef struct s_game
{
	char	*filename;
	int		filename_fd;
}	t_game;

// main.c
void	init_struct(t_game *game);
void	free_exit(t_game *game, int code);

// parser.c
int		parser(int argc, char **argv, t_game *game);
int		open_map(char *filename, t_game *game);

#endif