/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 21:58:41 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/07 21:58:43 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node

// void	f(void *content)
// {
// 	if (content == NULL)
// 		return ;
// }

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void ft_print_list(t_list *lst)
// {
// 	t_list *temp;

// 	temp = lst;
// 	while (temp != NULL)
// 	{
// 		printf("%s \n", (char *)temp->content);
// 		temp = temp->next;
// 	}
// }

// int	main(void)
// {
// 	t_list *lst = NULL;
// 	t_list *new_list;

// 	char	*first = "node1";
// 	t_list *node1 = ft_lstnew(first);
// 	ft_lstadd_front(&lst, node1);
// 	char	*second = "node2";
// 	t_list *node2 = ft_lstnew(second);
// 	ft_lstadd_front(&lst, node2);
// 	char	*third = "node3";
// 	t_list *node3 = ft_lstnew(third);
// 	ft_lstadd_front(&lst, node3);
// 	ft_lstiter(lst, f);
// 	return(0);
// }
