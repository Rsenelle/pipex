/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:46:54 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/09 20:28:26 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	execute_command(t_struct *s_pipex, char **env)
{
	int		i;
	char	*res_path;

	i = 0;
	if (!access(s_pipex->cmd[0], 0 | 1))
	{
		if (execve(s_pipex->cmd[0], s_pipex->cmd, env))
			perror("Error10");
	}
	else
	{
		while (s_pipex->path[i])
		{
			res_path = ft_strjoin(s_pipex->path[i], "/");
			res_path = ft_strjoin(res_path, s_pipex->cmd[0]);
			if (!access(res_path, 0 | 1))
				if (execve(res_path, s_pipex->cmd, env))
					perror("Error7");
			i++;
		}
		ft_error("command not found");
	}
}

void	add_command_to_array(char *argv, t_struct *s_pipex)
{
	s_pipex->cmd = ft_split(argv, ' ');
	if (!s_pipex->cmd)
		ft_error("Split error");
}

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

void	ft_perror(char *s)
{
	if (s)
	{
		perror(s);
		exit (1);
	}
	else
	{
		perror("Error");
		exit (1);
	}
}

void	init_struct(t_struct *s_pipex)
{
	s_pipex->fd[0] = 0;
	s_pipex->fd[1] = 0;
	s_pipex->fd_input = 0;
	s_pipex->fd_output = 0;
	s_pipex->cmd = NULL;
	s_pipex->path = NULL;
	s_pipex->flag = 0;
	s_pipex->fd_here = 0;
}
