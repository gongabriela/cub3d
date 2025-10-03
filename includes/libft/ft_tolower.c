/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tolower.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:33:17 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/21 14:35:52 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// returns its uppercase equivalent, if an uppercase repre‐
// sentation exists in the current locale.  Otherwise, it returns c.

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	return (c);
}

// int main(void)
// {
// 	char	i;
// 	char	c;

//     i = 'A';
//     while (i <= 'Z')
//     {
//         c = ft_tolower(i);
//         write(1, &c, 1);
//         i++;
//     }
// }
