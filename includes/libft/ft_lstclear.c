/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:46:25 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/07 21:46:27 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.

// void	del(void *content)
// {
// 	free(content);
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	temp = *lst;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

// void ft_print_list(t_list *lst)
// {
// 	t_list *temp;

// 	temp = lst;
// 	if (temp == NULL)
// 	{
// 		printf("list is empty");
// 		return ;
// 	}
// 	while (temp != NULL)
// 	{
// 		printf("%s ", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }

// int	main(void)
// {
// 	t_list *lst = NULL;

// 	char	*first = ft_strdup("node1");
// 	t_list *node1 = ft_lstnew(first);
// 	ft_lstadd_front(&lst, node1);
// 	char	*second = ft_strdup("node2");
// 	t_list *node2 = ft_lstnew(second);
// 	ft_lstadd_front(&lst, node2);
// 	char	*third = ft_strdup("node3");
// 	t_list *node3 = ft_lstnew(third);
// 	ft_lstadd_front(&lst, node3);
// 	printf("List before clear: ");
// 	ft_print_list(lst);
// 	ft_lstclear(&lst, del);
// 	printf("\nList after clear: ");
// 	ft_print_list(lst);
// 	return(0);
// }
