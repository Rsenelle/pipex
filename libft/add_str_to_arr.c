/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:37:13 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/03 23:00:18 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_else(char *s)
{
	char	**res;

	res = malloc(sizeof(char *) + 1);
	if (!res)
		return (NULL);
	res[0] = ft_strdup(s);
	res[1] = NULL;
	return (res);
}

char	**add_str_to_arr(char **arr, int size, char *s)
{
	int		i;
	char	**res;

	if (arr && s)
	{
		res = malloc(sizeof(char *) * (size + 1) + 1);
		if (!res)
			return (NULL);
		i = -1;
		while (arr[++i])
			res[i] = ft_strdup(arr[i]);
		res[i] = ft_strdup(s);
		res[++i] = NULL;
		free_buf(arr);
		return (res);
	}
	else if (s && !arr)
		return (ft_else(s));
	return (NULL);
}
