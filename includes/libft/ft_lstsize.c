/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:56:03 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/07 18:56:05 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the number of nodes in a list

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	i = 0;
	temp = lst;
	while (temp != NULL)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

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
// 	printf("%d", ft_lstsize(lst));
// 	return(0);
// }