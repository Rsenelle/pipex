/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 23:59:38 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/14 00:20:27 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	s;
	{
		if (n == -2147483648)
		{
			write(fd, "-", 1);
			write(fd, "2", 1);
			ft_putnbr_fd(147483648, fd);
		}
		else if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
			ft_putnbr_fd(n, fd);
		}
		else if (n < 10)
		{
			s = n + '0';
			write(fd, &s, 1);
		}
		else
		{
			ft_putnbr_fd(n / 10, fd);
			ft_putnbr_fd(n % 10, fd);
		}
	}
}
