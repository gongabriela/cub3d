/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:38:58 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/07 19:39:00 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Takes as a parameter a node and frees the memory of
// the node’s content using the function ’del’ given
// as a parameter and free the node. The memory of
// ’next’ must not be freed

// void	del(void *content)
// {
// 	free(content);
// }

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}

// int	main(void)
// {
// 	t_list *node1;

// 	char	*first = ft_strdup("node1");
// 	node1 = ft_lstnew(first);
// 	ft_lstdelone(node1, del);
// 	return(0);
// }