/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toupper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:33:17 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/21 14:35:52 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns its lowercase equivalent, if an uppercase repre‐
// sentation exists in the current locale.  Otherwise, it returns c.

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c = c - 32;
	}
	return (c);
}

// int	main(void)
// {
// 	char	c = 'a';
// 	printf("%c", (char)ft_toupper(c));
// 	return (0);
// }