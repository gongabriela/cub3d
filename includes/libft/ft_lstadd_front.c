/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:56:34 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/06 13:56:35 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Adds the node ’new’ at the beginning of the list

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		new->next = NULL;
	}
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

// void ft_print_list(t_list *lst)
// {
// 	t_list *temp;

// 	temp = lst;
// 	while (temp != NULL)
// 	{
// 		printf("%s ", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }

// int	main(void)
// {
// 	t_list *lst = NULL;

// 	char	*first = "node1";
// 	t_list *node1 = ft_lstnew(first);
// 	ft_lstadd_front(&lst, node1);
// 	char	*second = "node2";
// 	t_list *node2 = ft_lstnew(second);
// 	ft_lstadd_front(&lst, node2);
// 	char	*third = "node3";
// 	t_list *node3 = ft_lstnew(third);
// 	ft_lstadd_front(&lst, node3);
// 	ft_print_list(lst);
// 	return(0);
// }
