/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 16:23:09 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/25 16:23:13 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Alloc memory for an array of nmemb of size bytes each
/// nmemb - Number of elements
/// size - Size of each element
/// return - SUCCESS(Pointer to the allocated memory)
/// return - FAILURE(NULL)

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*array;
	unsigned char	*parray;
	size_t			i;
	size_t			totalsize;

	i = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	totalsize = nmemb * size;
	array = (void *)malloc(totalsize);
	if (array == NULL)
		return (NULL);
	parray = (unsigned char *)array;
	while (i < nmemb * size)
	{
		parray[i] = 0;
		i++;
	}
	return (array);
}

// int	main (void)
// {
// 	size_t	nmemb = 5;
// 	size_t 	size = sizeof(int);
// 	int		*array;

// 	array = (int *)ft_calloc(nmemb, size);
// 	if (array == NULL)
// 	{
// 		printf("Falha na alocacao");
// 		return (0);
// 	}
// 	printf("Array alocado e inicializado com 0");
// 	return (0);
// }
