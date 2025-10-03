/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:24:18 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/14 15:24:19 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// prints an unsigned integer 

int	print_unbr(unsigned int n)
{
	int		count;

	count = 0;
	if (n >= 10)
	{
		count = count + print_nbr(n / 10);
	}
	count = count + print_char(n % 10 + '0');
	return (count);
}
