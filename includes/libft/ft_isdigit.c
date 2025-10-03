/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isdigit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:49:52 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/21 14:31:45 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Checks if character is a digit
/// c -	character to check
/// return		SUCCESS(1)
/// return		FAILURE(0)

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c;

// 	c = '0';
// 	printf("%d", ft_isdigit(c));
// 	return (0);
// }
