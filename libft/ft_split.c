/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 19:42:26 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/03 22:01:07 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_kolvoslov(const char *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			k++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (k);
}

static char	**ft_free(char **res)
{
	if (res)
	{
		while (*res)
		{
			free(*res);
			*res = NULL;
			(*res)++;
		}
		free(res);
		res = NULL;
	}
	return ((char **) NULL);
}

static char	**ft_putstring(int k, char const *s, char c, char **res)
{
	unsigned int	i;
	int				numstr;
	unsigned int	lastletter;

	i = 0;
	numstr = 0;
	while (numstr < k)
	{
		lastletter = 0;
		while (s[i] != c && s[i])
		{
			i++;
			lastletter++;
		}
		if (lastletter)
		{
			res[numstr] = ft_substr(s, (i - lastletter), lastletter);
			if (res[numstr] == NULL)
				return (ft_free(res));
			numstr++;
		}
		i++;
	}
	res[numstr] = NULL;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char			**res;

	if (!s)
		return (NULL);
	res = (char **)malloc((sizeof(char *) * (ft_kolvoslov(s, c) + 2)));
	if (!res)
		return (NULL);
	res = ft_putstring(ft_kolvoslov(s, c), s, c, res);
	return (res);
}
