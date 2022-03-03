/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_buf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:39:56 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/03 23:05:09 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_buf(char **buf)
{
	int	i;

	i = 0;
	if (!buf)
		return ;
	while (buf[i])
	{
		free (buf[i]);
		buf[i] = NULL;
		i++;
	}
	free(buf);
	buf = NULL;
}
