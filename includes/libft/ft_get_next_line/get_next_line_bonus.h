/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:03:15 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/15 17:03:17 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define MAX_FD 1024

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_list
{
	char			*str;
	struct s_list	*next;
}	t_list;

void	ft_list_prep(t_list **list);
char	*ft_get_line(t_list *list);
void	ft_append_list(t_list **list, char *buf);
void	ft_list_add(t_list **list, int fd);
char	*get_next_line(int fd);
void	ft_dealloc(t_list **list, t_list *clean_node, char *buf);
int		ft_len_list(t_list *list);
void	ft_copy_str(t_list *list, char *new_str);
t_list	*ft_find_last_node(t_list *list);
int		ft_found_newline(t_list *list);

#endif
