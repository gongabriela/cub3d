/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:26:35 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/09 12:26:35 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_colors(char *line, t_map *map_info, int rgb[3])
{
	int	i;

	if (!line)
		return (free_exit("Invalid RGB value.", map_info, 1), 1);
	if (rgb[0] != -1 || rgb[1] != -1 || rgb[2] != -1)
		return (free_exit("Duplicated RGB element.", map_info, 1), 1);
	line += 2;
	while (*line == ' ')
		line++;
	i = 0;
	while (*line && i < 3)
	{
		if (i != 0 && *line == ',')
			line++;
		rgb[i] = get_rgb_value(&line, map_info);
		i++;
	}
	if (i != 3 || (*line != '\0' && *line != '\n' && *line != '\r'
			&& *line != ' '))
		return (free_exit("Invalid RGB value.", map_info, 1), 1);
	while (*line == ' ' || *line == '\t')
		line++;
	if (*line != '\0' && *line != '\n' && *line != '\r')
		return (free_exit("Too many elements for color info.", map_info, 1), 1);
	return (0);
}

int	get_rgb_value(char **line, t_map *map_info)
{
	int		len;
	char	*tmp;
	int		nbr;

	len = 0;
	while (**line && ft_isdigit(**line))
	{
		len++;
		(*line)++;
	}
	if (len == 0 || len > 3 || (**line != ',' && **line != '\0'
			&& **line != '\n' && **line != '\r' && **line != ' '
			&& **line != '\t'))
		return (free_exit("Invalid RGB value.", map_info, 1), -1);
	tmp = ft_substr(*line - len, 0, len);
	if (!tmp)
		return (free_exit("Memory allocation failed.", map_info, 1), -1);
	nbr = ft_atoi(tmp);
	free(tmp);
	return (nbr);
}
