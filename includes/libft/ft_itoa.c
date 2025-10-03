/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:40:16 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/29 13:40:18 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// Converts an integer to a string
/// n - number to convert
/// return		SUCCESS(Pointer to the string)
/// return		FAILURE(NULL)

static int	ft_size(long n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static long	ft_positive(long n)
{
	n = n * -1;
	return (n);
}

static char	*ft_alloc(int size)
{
	char	*str;

	if (size == 0)
	{
		str = (char *) malloc(sizeof(char) * 2);
		if (str == NULL)
			return (NULL);
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = (char *) malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	return (str);
}

char	*ft_itoa(int n)
{
	long	nbr;
	char	*str;
	int		size;

	nbr = n;
	size = 0;
	if (n == 0)
		return (ft_alloc(size));
	size = ft_size(nbr);
	str = ft_alloc(size);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		nbr = ft_positive(nbr);
		str[0] = '-';
	}
	str[size--] = '\0';
	while (nbr > 0)
	{
		str[size--] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	return (str);
}

// int main(void)
// {
// 	int n = -2147483648;

// 	printf("%s", ft_itoa(n));
// 	return (0);
// }
