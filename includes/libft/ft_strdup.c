/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:56:31 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/26 15:56:38 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// copies, allocates and returns a pointer to the coppied string 
// s - the string to be coppied
// return  SUCCESS(pointer to new string)
// return  FAILURE(returns NULL)

char	*ft_strdup(const char *s)
{
	char	*sdup;
	int		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	sdup = (char *) malloc(sizeof(char) * (i + 1));
	if (sdup == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		sdup[i] = s[i];
		i++;
	}
	sdup[i] = '\0';
	return (sdup);
}

// int main() {
//     const char *str = "Hello, world!";
//     char *dup_str = ft_strdup(str);

//     if (dup_str != NULL) 
// 	{
//         printf("Duplicated string: %s\n", dup_str);
//         free(dup_str);
//     } else 
// 	{
//         printf("Memory allocation failed\n");
//     }
//     return 0;
// }
