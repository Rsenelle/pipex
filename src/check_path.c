/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 19:29:49 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/03 21:55:32 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	count_path_strings(t_struct *s_pipex)
{
	int	i;

	i = 0;
	if (s_pipex->path)
		while (s_pipex->path[i])
			i++;
	return (i);
}

int	check_pwd(char **env, t_struct *s_pipex)
{
	int		i;
	char	*temp;
	int		size;

	i = 0;
	size = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
		{
			temp = ft_strchr(env[i], '/');
			size = count_path_strings(s_pipex);
			s_pipex->path = add_str_to_arr(s_pipex->path, size, temp);
			if (!s_pipex->path)
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_path(char **env, t_struct *s_pipex)
{
	int		i;
	char	*temp;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			temp = ft_strchr(env[i], '/');
			if (!temp)
				return (1);
			s_pipex->path = ft_split(temp, ':');
			if (!(s_pipex->path))
				return (1);
		}
		i++;
	}
	if (check_pwd(env, s_pipex))
		return (1);
	return (0);
}
