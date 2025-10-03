/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:31:55 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/21 14:30:59 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///	Checks if character is alphabetic
/// c - character to check
/// return		SUCCESS(1)
/// return		FAILURE(0)

int	ft_isalpha(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = 'a';
// 	printf("%d", ft_isalpha(c));
// 	return (0); 
// }
