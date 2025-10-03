/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:14:17 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/30 13:14:19 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// function returns a pointer to the last 
// occurrence of  the  character  c  in  the
// string s.

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i--;
	}
	return (NULL);
}

// int main (void)
// {
// 	char	*str = "ola tudo bem";
// 	char	c = 'e';

// 	printf("%s", ft_strrchr(str, c));
// 	return (0);
// }