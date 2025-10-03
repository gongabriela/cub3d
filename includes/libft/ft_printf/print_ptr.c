/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:23:58 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/13 16:24:00 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// prints the adress of a pointer

static char	*symbols(void)
{
	return ("0123456789abcdef");
}

static int	print_recursive(unsigned long ptr)
{
	char	*hex_digits;
	int		count;

	count = 0;
	hex_digits = symbols();
	if (ptr < 16)
		count = print_char(hex_digits[ptr]);
	else
	{
		count = count + print_recursive(ptr / 16);
		count = count + print_char(hex_digits[ptr % 16]);
	}
	return (count);
}

int	print_ptr(unsigned long ptr)
{
	int		count;

	count = 0;
	if (!ptr)
	{
		return (write(1, "(nil)", 5));
	}
	count = count + write(1, "0x", 2);
	count = count + print_recursive(ptr);
	return (count);
}
