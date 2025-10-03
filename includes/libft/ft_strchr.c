/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    strchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:33:17 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/21 14:35:52 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Searches for the first occurrence of the character c
/// s The string to be searched
/// c The character to search for
/// return A pointer to the first occurrence of the character c in the string s

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

// int main(void) 
// {
//     const char *str = "Hello, world!";
//     char c = 'o';

//     char *result = ft_strchr(str, c);
//     if (result) 
// 	{
//         printf("Found '%c' at position: %ld\n", c, result - str);
//     } else 
// 	{
//         printf("Character '%c' not found.\n", c);
//     }
//     return 0;
// }
