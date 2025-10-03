/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:48:32 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/24 17:37:32 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Sets the first n bytes of the memory area pointed to by s to 0.
/// s - Memory area
/// n - Number of bytes to be set to 0

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

// int	main(void)
// {
// 	char str[10] = "Teste123";
// 	printf("Antes do ft_bzero: %s\n", str);
// 	ft_bzero(str, 10);
// 	printf("Depois do ft_bzero: %s\n", str);
// 	return (0);
// }
