/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:31:24 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/10/06 14:31:24 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parser(int argc, char **argv, t_game *game)
{
	if (argc != 2)
		return (printf("Error\nInvalid number of arguments.\n"), 1);
	if (!open_map(argv[1], game))
		return (1);
	alloc_mem(game);
	if (parse_file(game))
		return (1);
	close(game->filename_fd);
	game->filename_fd = -1; 
	return (0);
}

int	open_map(char *filename, t_game *game)
{
	int	len;

	len = strlen(filename);
	if (len < 4 || strcmp(&filename[len - 4], ".cub") != 0)
		return (printf("Error\nInvalid file extension\n"), 0);
	game->filename = filename;
	game->filename_fd = open(filename, O_RDONLY);
	if (game->filename_fd > 0)
		return (1);
	return (printf("Error\nCould not open file: %s\n", filename), 0);
}

int	parse_file(t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(game->filename_fd);
	while (line)
	{
		
		if (ft_strncmp(line, "NO ", 3) == 0)
			parse_textures(&line, game, &game->no_texture); //ja mandar a line - 3?? mandar como **
		else if (ft_strncmp(line, "SO ", 3) == 0)
			parse_textures(line, game, &game->so_texture);
		else if (ft_strncmp(line, "WE ", 3) == 0)
			parse_textures(line, game, &game->we_texture);
		else if (ft_strncmp(line, "EA ", 3) == 0)
			parse_textures(line, game, &game->ea_texture);
		else if (ft_strncmp(line, "F ", 2) == 0)
			parse_colors(line, game, game->f_rgb);
		else if (ft_strncmp(line, "C ", 2) == 0)
			parse_colors(line, game, game->c_rgb);
		else if (line[0] == '1' || line[0] == '0')
			parse_map(game, line);
		else if (line[0] != '\n')
			invalid_element_error(game);
			free(line);
		line = get_next_line(game->filename_fd);
	}
	return (0);
}

void	parse_textures(char *line, t_game *game,)
{

}

void	parse_colors(char *line, t_game *game, int *rgb)
{

}

//funcao de eliminar espacos
//funcao de acabar com o get next line em caso de erro

/*int	parse_file_elements(t_game *game)
{
	char	*line;
	int		i;

	line = get_next_line(game->filename_fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (game->error == 0 && (line[i] == 'C' || line[i] == 'F'))
			parse_colors(line, i, game);
		else if (game->error == 0 && is_texture(line, i))
			parse_textures(line, i, game);
		else if (game->error == 0 && (line[i] == '1' || line[i] == '0'))
			parse_map(game);
		else
			invalid_element_error(game);
		free(line);
		line = get_next_line(game->filename_fd);
	}
	if (game->error == 1 || check_missing_elements(game))
		return (1);
	return (0);
}

int	check_missing_elements(t_game *game)
{
	if (game->no_texture < 0 || game->so_texture < 0
		|| game->we_texture < 0 || game->ea_texture < 0)
	{
		printf("Error\nMissing texture element.\n");
		return (1);
	}
	if (game->f_rgb[0] == -1 || game->f_rgb[1] == -1 || game->f_rgb[2] == -1
		|| game->c_rgb[0] == -1 || game->c_rgb[1] == -1 || game->c_rgb[2] == -1)
	{
		printf("Error\nMissing floor/ceiling element.\n");
		return (1);
	}
	if (!game->map)
	{
		printf("Error\nMap not found.\n");
		return (1);
	}
	return (0);
}*/


//podemos criar uma funcao expect que vai verificar se o elemento e NO,SO,WE,EA,C,F e tambem
	//guardar em uma variavel quais elementos ja foram lidos para verificar elementos duplicados

	//while line
		//if NO
			//parse_texture(NO, line, game, game->no_texture)
		//else if SO
			//parse_texture(SO, line, game, game->so_texture)
		//else if WE
			//parse_texture(WE, line, game,	 game->we_texture)
		//else if EA
			//parse_texture(EA, line, game, game->ea_texture)
		//else if C
			//parse_color(C, line, game, game->c_rgb)
		//else if F
			//parse_color(F, line, game, game->f_rgb)
		//else if map
			//se terminou de ler o mapa e line nao for vazia retornar map not at the end of file error
		//else
			//invalid element error

//criar funcao que vai terminar o get next line em caso de erro para nao gerar leak