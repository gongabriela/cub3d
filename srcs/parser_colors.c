/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 12:10:56 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/10/08 12:10:56 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_colors(char *line, int i, t_game *game)
{
	static int	floor = 0;
	static int	ceiling = 0;

	if (floor > 1 || ceiling > 1)
		return ;
	if (line[i] == 'F')
		floor++;
	else
		ceiling++;
	if (floor == 2 || ceiling == 2)
	{
		printf("Error\nDuplicated ceilling/floor element.\n");
		game->error = 1;
		return ;
	}
	while (line[i] == ' ')
		i++;
	if (parse_elements(line, i, game, line[i]))
	{
		printf("Error\nInvalid floor/ceiling RGB format.\n");
		game->error = 1;
	}
}

int	parse_elements(char *line, int i, t_game *game, char type)
{
	int	value;
	int	elements;

	elements = 0;
	while (line[i] && ft_isdigit(line[i]) && elements <= 2)
	{
		value = check_rgb(line, &i);
		if (value == -1)
			return (1);
		if (type == 'F')
			game->f_rgb[elements] = value;
		else
			game->c_rgb[elements] = value;
		elements++;
		if (line[i] == ',' && elements <= 2)
			i++;
	}
	if (line[i] != '\0' && line[i] != '\r' && line[i] != '\n')
		return (1);
	return (0);
}

int	check_rgb(char *line, int *i)
{
	int	value;
	int	j;

	j = *i;
	while (line[*i] && ft_isdigit(line[*i]))
		(*i)++;
	value = ft_atoi(ft_substr(line, j, *i - j));
	if (value < 0 || value > 255)
		return (-1);
	return (value);
}
