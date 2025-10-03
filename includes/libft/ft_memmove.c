/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:52:32 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/23 22:38:02 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Moves n bytes from memory area src to memory area dest
/// dest	Pointer to the destination memory area
/// src		Pointer to the source memory area
/// n		Number of bytes to be copied
/// return		SUCCESS(dest)
/// return		FAILURE(dest) 

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*pdest;
	const char	*psrc;

	pdest = (char *)dest;
	psrc = (const char *)src;
	if (pdest == psrc || n == 0)
		return (dest);
	if (pdest < psrc)
	{
		while (n--)
			*pdest++ = *psrc++;
	}
	if (pdest > psrc)
	{
		pdest = pdest + n;
		psrc = psrc + n;
		while (n--)
			*--pdest = *--psrc;
	}
	return (dest);
}

// int	main()
// {
// 	char	str[] = "abcdefghiu";

// 	memmove(str + 3, str + 1, 3);
// 	printf("%s", str);
// 	return (0);
// }
