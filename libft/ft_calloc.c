/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:17:40 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/09 20:29:16 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*d;
	size_t	i;

	d = malloc(count * size);
	if (d == 0)
		return (0);
	i = 0;
	while (i < size * count)
	{
		d[i] = 0;
		i++;
	}
	return ((void *)d);
}
