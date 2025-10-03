/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:30:02 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/25 15:30:08 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

///	Converts a string to an integer
/// str - string to convert
/// return - SUCCESS(integer)

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		num = num * 10 + nptr[i] - '0';
		i++;
	}
	return (num * sign);
}

// int     main(int argc, char *argv[])
// {
//     (void)argc;
//     printf("%d", ft_atoi(argv[1]));
//     return (0);
// }