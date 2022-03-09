/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:46:48 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/09 21:03:06 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(t_struct *s_pipex, char **env)
{
	close(s_pipex->fd[0]);
	if (dup2(s_pipex->fd[1], 1) < 0)
		ft_perror("Error1");
	close(s_pipex->fd[1]);
	execute_command(s_pipex, env);
}

void	parent_process(t_struct *s_pipex)
{
	wait(0);
	close(s_pipex->fd[1]);
	free_buf(s_pipex->cmd);
	if (dup2(s_pipex->fd[0], 0) < 0)
		ft_perror("Error2");
	close(s_pipex->fd[0]);
}

void	last_command(t_struct *s_pipex, char **argv, int argc, char **env)
{
	int			pid;

	add_command_to_array(argv[argc - 2], s_pipex);
	pid = fork();
	if (pid == 0)
	{
		if (s_pipex->fd_here)
		{
			if (dup2(s_pipex->fd_here, 1) < 0)
				ft_perror("Error3");
		}
		else
		{
			if (dup2(s_pipex->fd_output, 1) < 0)
				ft_perror("Error3");
		}
		execute_command(s_pipex, env);
	}
}

void	change_fd(char **argv, int argc, t_struct *s_pipex)
{
	s_pipex->fd_input = open(argv[1], O_RDONLY);
	if (s_pipex->fd_input < 0)
		ft_perror("Error5");
	if (dup2(s_pipex->fd_input, 0) < 0)
		ft_perror("Error6");
	close(s_pipex->fd_input);
	s_pipex->fd_output = open(argv[argc - 1], \
						O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (s_pipex->fd_output < 0)
		ft_perror("Error7");
	if (dup2(s_pipex->fd_output, 1) < 0)
		ft_perror("Error8");
}
