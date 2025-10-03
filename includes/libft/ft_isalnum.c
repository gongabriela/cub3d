/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:04:41 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/21 14:54:20 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Checks if character is alphanumeric
/// c - character to check
/// return - SUCCESS(1)
/// return - FAILURE(0)

int	ft_isalnum(int c)
{
	if ((c >= 97 && c <= 122) || (c >= 65 && c <= 90)
		|| (c >= 48 && c <= 57))
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = '2';
// 	printf("%d", ft_isalnum(c));
// 	return (0);
// }
