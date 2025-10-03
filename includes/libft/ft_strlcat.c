/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:02:15 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/23 18:20:28 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function appends the NUL-terminated string 
// src to the end of dst.  It will append  at most size
// dest - dest to src
// src - str to copy
// size - maximum char to cpy

int	ft_strlcat(char *dest, const char *src, size_t size)
{
	int		i;
	size_t	len_dest;
	size_t	len_src;

	i = 0;
	len_src = 0;
	len_dest = 0;
	while (dest[len_dest] != '\0' && len_dest < size)
		len_dest++;
	while (src[len_src] != '\0')
		len_src++;
	if (size <= len_dest)
		return (len_src + size);
	while (src[i] != '\0' && (len_dest + i) < (size -1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + len_src);
}

// int	main(void)
// {
// 	const char	*src = "rita";
// 	char		dest[15] = "ola";
// 	size_t		size = 15;
// 	printf("%d", ft_strlcat(dest, src, size));
// 	return (0);
// }
