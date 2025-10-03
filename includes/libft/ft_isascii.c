/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:33:17 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/21 14:35:52 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// checks if param is in the ascii table
// c - param check 
// return SUCCESS(1)
// return FAILURE(0)

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

// int	main(void)
// {
// 	int	c = 3;

// 	printf("%d", ft_isascii(c));
// 	return(0);
// }
