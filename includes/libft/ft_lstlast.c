/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:06:46 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/07 19:06:47 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the last node of the list

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}

// int	main(void)
// {
// 	t_list	*lst = NULL;
// 	t_list	*last_node;

// 	char	*first = "node1";
// 	t_list *node1 = ft_lstnew(first);
// 	ft_lstadd_front(&lst, node1);
// 	char	*second = "node2";
// 	t_list *node2 = ft_lstnew(second);
// 	ft_lstadd_front(&lst, node2);
// 	char	*third = "node3";
// 	t_list *node3 = ft_lstnew(third);
// 	ft_lstadd_front(&lst, node3);
// 	last_node = ft_lstlast(lst);
// 	printf("%s", (char *)last_node->content);
// 	return(0);
// }