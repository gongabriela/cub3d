/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsampaio <rsampaio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:10:18 by rsampaio          #+#    #+#             */
/*   Updated: 2024/11/07 22:41:38 by rsampaio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

// void	del(void *content)
// {
// 	free(content);
// }

// void	*f(void *content)
// {
// 	char	*new_content = malloc(sizeof(char));
// 	if (new_content == NULL)
// 		return (NULL);
// 	*new_content = (char)ft_toupper(*(char *)content);
// 	return new_content;
// }

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	t_list	*temp;

	new_list = NULL;
	while (lst != NULL)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			while (new_list != NULL)
			{
				temp = new_list->next;
				del(new_list->content);
				free(new_list);
				new_list = temp;
			}
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
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
// 	printf ("Lista a ser copiada: \n");
// 	ft_print_list(lst);
// 	printf ("Lista copiada: \n");
// 	new_list = ft_lstmap(lst, f, del);
// 	ft_print_list(new_list);
// 	return(0);
// }
