/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:36:11 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/21 14:53:35 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Checks if character is printable
/// c - character to check
/// return		SUCCESS(1)
/// return		FAILURE(0)

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	char	c = 'c';

// 	printf("%d", ft_isprint(c));
// 	return (0);
// }
