/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:42:23 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/13 16:00:34 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;
	size_t	len;

	i = 0;
	k = 0;
	len = ft_strlen(dst);
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	if (dstsize > ft_strlen(dst) + 1)
	{
		k = ft_strlen(dst);
		while (k < dstsize - 1 && src[i])
		{
			dst[k] = src[i];
			i++;
			k++;
		}
		dst[k] = '\0';
	}
	return (len + ft_strlen(src));
}
