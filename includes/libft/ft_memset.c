/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:15:42 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/23 12:45:13 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Sets the first n bytes of the memory area pointed to by s to c
/// s	Pointer to the memory area
/// c	Character to be set
/// n	Number of bytes to be set
/// return		SUCCESS(s)

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s2;

	i = 0;
	s2 = s;
	while (i < n)
	{
		*s2 = (unsigned char)c;
		s2++;
		i++;
	}
	return (s);
}

// int main(void) {
//     size_t n = 10;
//     char buffer[10];

//     ft_memset(buffer, 'X', n);
//     buffer[n - 1] = '\0';
//     printf("Buffer após ft_memset: %s\n", buffer);
//     memset(buffer, 'O', n);
//     printf("Buffer após memset: %s\n", buffer);
//     return 0;
// }
