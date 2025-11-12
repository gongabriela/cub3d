/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggoncalv <ggoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 11:05:14 by ggoncalv          #+#    #+#             */
/*   Updated: 2025/11/12 12:08:49 by ggoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//cria a matriz com bordas
//OBS: verificar se a linha anterior era maior que a atual (minimo -2, se for -1 a borda ainda fica fechada), para fechar a borda
void    create_ff_matrix(t_map *map_info)
{
    int i;
    int size;
    int prev_size;

    map_info->ff_matrix = malloc(sizeof(char *) * (map_info->height + 3));
    if (!map_info->ff_matrix)
        free_exit("Memory allocation failed for ff_matrix.", map_info, 1);
    i = 0;
    prev_size = 0;
    while (i < map_info->height + 2)
    {
        if (i == 0) //tamanho da primeira linha + 2 para a borda
            size = ft_strlen(map_info->char_matrix[0]) + 2;
        else if (i == map_info->height + 1) //tamanho da ultima linha + 2 para a borda
            size = ft_strlen(map_info->char_matrix[map_info->height - 1]) + 2;
        else //tamanho das linhas originais + 2 para as bordas
            size = ft_strlen(map_info->char_matrix[i - 1]) + 2;
        if (size + 1 < prev_size) //garante que a borda fecha
            size = prev_size - 1;
        map_info->ff_matrix[i] = malloc(sizeof(char) * (size + 1));
        if (!map_info->ff_matrix[i])
            free_exit("Memory allocation failed for ff_matrix row.", map_info, 1);
        fill_ff_matrix_row(map_info, i, size);
        prev_size = (int)ft_strlen(map_info->ff_matrix[i]);
        i++;
    }
    map_info->ff_matrix[i] = NULL;
}

//preenche uma linha da ff_matrix
void    fill_ff_matrix_row(t_map *map_info, int row, int size)
{
    int i;
    int char_len;

    i = 0;
    if (row > 0 && row < map_info->height + 1)
        char_len = ft_strlen(map_info->char_matrix[row - 1]);
    else
        char_len = 0;
    while (i < size)
    {
        if (row == 0 || row == map_info->height + 1)
            map_info->ff_matrix[row][i] = 'X';
        else if (i == 0 || i > char_len)
            map_info->ff_matrix[row][i] = 'X';
        else
        {
            map_info->ff_matrix[row][i] = map_info->char_matrix[row - 1][i - 1];
            if (ft_strchr("NSEW", map_info->ff_matrix[row][i]))
            {
                map_info->player_pos[0] = row;
                map_info->player_pos[1] = i;
                map_info->player_ori = map_info->ff_matrix[row][i];
                map_info->ff_matrix[row][i] = '0';
            }
        }
        i++;
    }
    if (i == size)
        map_info->ff_matrix[row][i] = '\0';

}


