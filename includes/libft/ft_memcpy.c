/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:59:43 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/23 13:12:49 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Copies n bytes from memory area src to memory area dest
/// dest	Pointer to the destination memory area
/// src		Pointer to the source memory area
/// n		Number of bytes to be copied
/// return		SUCCESS(dest)
/// return		FAILURE(NULL)

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*pdest;
	const char	*psrc;

	if (!dest && !src)
		return (NULL);
	pdest = (char *)dest;
	psrc = (const char *)src;
	i = 0;
	while (i < n)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return (dest);
}
// int	main(void)
// {
// 	char	*src = "Hello, World!";
// 	char	*dest[20];

// 	printf("%s", (char *)ft_memcpy(dest, src, 13));
// 	return (0);
// }