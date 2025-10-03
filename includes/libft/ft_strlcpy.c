/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:31:28 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/24 12:52:32 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function copies up to size - 1 characters 
// from the NUL-terminated string src to dst, 
// NUL-terminating the result.
// return the total length of the string they tried to create.

size_t	ft_strlcpy(char *dst, char const *src, size_t size)
{
	size_t	i;
	size_t	len_src;

	i = 0;
	len_src = 0;
	while (src[len_src] != '\0')
	{
		len_src++;
	}
	if (size > 0)
	{
		while (src[i] != '\0' && size - 1 > i)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len_src);
}

// int main()
// {
//     char src[] = "Hello, World!";
//     char dst[20]; 
//     size_t size = 10;
//     size_t len = ft_strlcpy(dst, src, size);
//     printf("ft_strlcpy: %s\n", dst);
//     printf("Returned length: %zu\n", len);
// }
