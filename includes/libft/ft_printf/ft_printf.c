/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:24:36 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/12 14:24:37 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count = count + print_char(va_arg(ap, int));
	else if (specifier == 's')
		count = count + print_str(va_arg(ap, char *));
	else if (specifier == 'd')
		count = count + print_nbr(va_arg(ap, int));
	else if (specifier == 'p')
		count = count + print_ptr(va_arg(ap, unsigned long));
	else if (specifier == 'i')
		count = count + print_nbr(va_arg(ap, int));
	else if (specifier == 'u')
		count = count + print_unbr(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		count = count + print_hexa(va_arg(ap, unsigned int), specifier);
	else if (specifier == '%')
		count = count + print_char('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
			count = count + ft_print_format(*(++format), ap);
		else
			count = count + write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int		count;
// 	char	*ptr;

// 	count = 0;
// 	count =	ft_printf("print letter: %c ", 'a');
// 	ft_printf(" | count = %d\n", count);
// 	count = ft_printf("print string: %s", "the string has been printed");
// 	ft_printf(" | count = %d\n", count);
// 	count = ft_printf("print decimal: %d", 1996);
// 	ft_printf(" | count = %d\n", count);
// 	count = ft_printf("print pointer: %p", ptr + 914619);
// 	ft_printf(" | count = %d\n", count);
// 	count = ft_printf("print integer: %i", 6991);
// 	ft_printf(" | count = %d\n", count);
// 	count = ft_printf("print unsigned decimal: %i", 9916);
// 	ft_printf(" | count = %d\n", count);
// 	count = ft_printf("print adress lowercase: %x", 42);
// 	ft_printf(" | count = %d\n", count);
// 	count = ft_printf("print adress uppercase: %X", 42);
// 	ft_printf(" | count = %d\n", count);
// 	count = ft_printf("print a percent sign: %%", 42);
// 	ft_printf(" | count = %d\n", count);
// 	return (0);
// }