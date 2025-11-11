/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 16:26:41 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/09 16:26:41 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    parse_map(t_map *map_info)
{
    read_map(map_info);
    printf("\nPRE-PARSING\n\n%s\n\nWidth: %d\nHeight: %d\n\n", map_info->line, map_info->width, map_info->height);
    free_exit(NULL, map_info, 0);
}




//create_ff_matrix
    //converte a string em uma matriz de chars
    //cria uma borda de Xs ao redor do mapa.

//flood fill algorithm
    //verifica se o mapa e fechado

//create_int_matrix
    //converte a matriz de chars em uma matriz de ints
    //preenche os espacos vazios com 0s para ser um mapa retangular
    //guarda a posicao do jogador e sua orientacao