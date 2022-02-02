/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:03:27 by rsenelle          #+#    #+#             */
/*   Updated: 2021/10/14 16:50:46 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == ((unsigned char)c))
			return ((char *)s);
		s++;
	}
	if ((*s == '\0') && ((unsigned char)c == '\0'))
		return ((char *)s);
	return (NULL);
}
