/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 19:28:59 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/07 19:29:00 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the node ’new’ at the end of the list

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
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
// 	ft_lstadd_back(&lst, node3);
// 	last_node = ft_lstlast(lst);
// 	printf("%s", (char *)last_node->content);
// 	return(0);
// }
