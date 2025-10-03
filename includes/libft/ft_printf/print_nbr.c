/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:50:22 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/13 15:50:24 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// prints a integer 

int	print_nbr(int n)
{
	long	nbr;
	int		count;

	nbr = n;
	count = 0;
	if (nbr < 0)
	{
		count = count + print_char('-');
		nbr = nbr * (-1);
	}
	if (nbr >= 10)
	{
		count = count + print_nbr(nbr / 10);
	}
	count = count + print_char(nbr % 10 + '0');
	return (count);
}
