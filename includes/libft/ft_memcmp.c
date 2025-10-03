/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:05:44 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/24 16:06:13 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Compares the first n bytes of s1 and s2
/// s1	Pointer to the first memory area
/// s2	Pointer to the second memory area
/// return		SUCCESS(difference between s1 and s2)
/// return		FAILURE(0)

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*ps1;
	const unsigned char	*ps2;

	ps1 = (const unsigned char *)s1;
	ps2 = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
	{
		return (0);
	}
	while (i < n)
	{
		if (ps1[i] != ps2[i])
			return (ps1[i] - ps2[i]);
		i++;
	}
	return (0);
}

/*int main (void)
{
    char    *s1 = "whats up";
    char    *s2 = "whats Up";
    int     n = 8;

    printf("%d", ft_memcmp(s1, s2, n));
    return (0);
}*/