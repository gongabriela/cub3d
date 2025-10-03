/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:20:01 by jpedro-f          #+#    #+#             */
/*   Updated: 2024/10/30 16:20:03 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// writes the number passed as a int 

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;
	char	print;

	nbr = n;
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nbr < 0)
	{
		write(fd, "-", 1);
		nbr = nbr * -1;
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	print = (nbr % 10) + '0';
	write(fd, &print, 1);
}

// int main(void)
// {
// 	int	num = 12332;

// 	ft_putnbr_fd(num, 1);
// 	return (0);
// }