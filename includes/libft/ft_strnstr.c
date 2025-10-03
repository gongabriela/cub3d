/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:45:13 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/24 16:45:15 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function locates the first occurrence of the 
// null-terminated string little in the
// string big, where not more than len characters are searched.

char	*ft_strnstr(const char *big, const char *litlle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*litlle == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		if (big[i] == litlle[j])
		{
			while (i + j < len && big[i + j] == litlle[j])
			{
				j++;
				if (litlle[j] == '\0')
					return ((char *)&big[i]);
			}
		}
		i++;
	}
	return (NULL);
}

// int     main(void)
// {
//     char    *big = "o meu nome e joao";
//     char    *little = "nome";
//     int     len = 10;

//     printf("%s", ft_strnstr(big, little, len));
//     return (0);
// }