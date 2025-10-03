/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:35:44 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/14 15:35:46 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// prints the adress of a pointer

static char	*symbols(char specifier)
{
	if (specifier == 'x')
		return ("0123456789abcdef");
	return ("0123456789ABCDEF");
}

int	print_hexa(unsigned long nbr, char specifier)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = symbols(specifier);
	if (nbr < 16)
		count = print_char(hex_digits[nbr]);
	else
	{
		count = count + print_hexa(nbr / 16, specifier);
		count = count + print_char(hex_digits[nbr % 16]);
	}
	return (count);
}
