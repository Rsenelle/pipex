/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 15:16:43 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/14 21:37:33 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenn(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	res = (char *)malloc (ft_lenn(n) + 1);
	if (!res)
		return (NULL);
	i = ft_lenn(n);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		res[0] = '-';
		n *= -1;
	}
	res[i] = '\0';
	while (n)
	{
		res[--i] = (n % 10) + '0';
		n = n / 10;
	}
	return (res);
}
