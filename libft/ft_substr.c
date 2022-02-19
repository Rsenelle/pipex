/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:17:35 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/15 16:21:47 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	j;

	j = 0;
	if (s == 0)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dst = malloc(sizeof(char));
		if (dst == 0)
			return (0);
	}
	else
	{
		if (ft_strlen(s) - start >= len)
			dst = malloc(sizeof(char) * (len + 1));
		else
			dst = malloc(sizeof(char) * (ft_strlen(s) - start + 1));
		if (dst == 0)
			return (0);
		while (s[start] && len--)
			dst[j++] = s[start++];
	}
	dst[j] = '\0';
	return (dst);
}
