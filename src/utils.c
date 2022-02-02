/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:46:54 by rsenelle          #+#    #+#             */
/*   Updated: 2022/02/02 19:21:01 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *s)
{
	if (!s)
		ft_putendl_fd("Error", 2);
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd(s, 2);
	}
	exit(1);
}

// int	check_space(char *s)
// {
// 	int i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == ' ')
// 			return (1);
// 		i++;
// 	}

// 	return (0);
// }
