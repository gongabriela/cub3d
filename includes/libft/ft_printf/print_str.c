/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:50:09 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/13 15:50:10 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// prints a string

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
	{
		return (write(1, "(null)", 6));
	}
	while (*str != '\0')
	{
		print_char(*str);
		count++;
		str++;
	}
	return (count);
}
