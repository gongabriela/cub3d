/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:57:45 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/27 15:57:48 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.

char	*ft_allocates(int start, int end)
{
	int		total;
	char	*str;
	int		i;

	i = 0;
	total = end - start + 1;
	if (total <= 0)
	{
		str = (char *) malloc (sizeof(char) * 1);
		if (str == NULL)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	str = (char *) malloc(sizeof(char) * total + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		len_s1;
	int		start;
	int		end;
	int		i;

	start = 0;
	end = 0;
	i = 0;
	len_s1 = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < len_s1)
		start++;
	end = len_s1 - 1;
	while (ft_strchr(set, s1[end]) && end >= start)
		end--;
	str = ft_allocates(start, end);
	if (str == NULL)
		return (NULL);
	while (i <= (end - start))
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int main(void)
// {
// 	char	*s1 = "lorem ipsum dolor sit amet";
// 	char	*set = "te";

// 	printf("%s", ft_strtrim(s1, set));
// 	return (0);
// }
