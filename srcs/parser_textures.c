/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:04:08 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/07 16:12:11 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	parse_textures(char *line, void *map_info, char **texture_path)
{
    (void)map_info;
    
	if (!line)
		return (printf("Error\nInvalid texture path.\n"));
	if (*texture_path != NULL)
		return (printf("Error\nDuplicated texture element.\n"));
	line += 3;
	while (*line == ' ' ||*line == '\t')
		line++;
	if (!line || ft_strncmp(line, "./", 2) != 0)
		return (printf("Error\nInvalid texture path.\n"));

    *texture_path = get_texture_path(map_info, line, get_len(line));
	if (!*texture_path)
		return (1);
	if (open_file(texture_path))
		return (1);
	/*if (check_for_more_elements(*texture_path, line))
		return (1);*/
	return (0);
}

/*int	check_for_more_elements(char *texture_path, char *line)
{
	char *p = path_end;

	while (*p == ' ' || *p == '\t')
		p++;
	if (*p != '\0' && *p != '\n' && *p != '\r')
	{
		free(*texture_path);
		*texture_path = NULL;
		printf("Error\nToo many elements on texture line.\n");
		return (1);
	}
    return 0;
}*/

int	open_file(char **texture_path)
{
	int	fd;
	
	fd = open(*texture_path, O_RDONLY);
	if (fd < 0)
	{
		free(*texture_path);
		*texture_path = NULL;
		printf("Error\nTexture file does not exist or cannot be opened.\n");
		return 1;
	}
	close(fd);
	return (0);
}

int     get_len(char *line)
{
    char    *path_end;

	path_end = line;
	while (*path_end && *path_end != ' ' && *path_end != '\n' && *path_end != '\r' && *path_end != '\t')
		path_end++;
	return(path_end - line);
}

char    *get_texture_path(t_map *map_info, char *line, int len)
{
	char	*texture_path;

	(void)map_info;
	
	if (len == 0)
        return (printf("Error\nInvalid texture path.\n"), NULL);
	char *tmp = (char *)malloc(len + 1);
	if (!tmp)
		return (printf("Error\nMemory allocation failed.\n"), NULL);
	ft_memcpy(tmp, line, len);
	tmp[len] = '\0';
	texture_path = ft_strdup(tmp);
	free(tmp);
	if (!texture_path)
		return (printf("Error\nMemory allocation failed.\n"), NULL);
	if (len < 4 || ft_strncmp((texture_path + (len - 4)), ".xpm", 4) != 0)
	{
		free(texture_path);
		texture_path = NULL;
		return (printf("Error\nInvalid texture file extension. Expected .xpm\n"), NULL);
	}
	return (texture_path);
}
