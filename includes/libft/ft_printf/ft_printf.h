/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:47:43 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/11/13 15:47:49 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_hexa(unsigned long nbr, char specifier);
int	print_unbr(unsigned int n);
int	print_ptr(unsigned long ptr);
int	print_nbr(int n);
int	print_char(char c);
int	print_str(char *str);
#endif
