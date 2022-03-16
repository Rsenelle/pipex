/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 19:46:48 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/11 15:16:11 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_process(t_struct *s_pipex, char **env)
{
	close(s_pipex->fd[0]);
	if (dup2(s_pipex->fd[1], 1) < 0)
		ft_perror("Error");
	close(s_pipex->fd[1]);
	execute_command(s_pipex, env);
}

void	parent_process(t_struct *s_pipex)
{
	close(s_pipex->fd[1]);
	free_buf(s_pipex->cmd);
	if (dup2(s_pipex->fd[0], 0) < 0)
		ft_perror("Error");
	close(s_pipex->fd[0]);
}

void	last_command(t_struct *s_pipex, char **argv, int argc, char **env)
{
	int			pid;

	add_command_to_array(argv[argc - 2], s_pipex);
	if (!s_pipex->cmd[0])
		ft_error("command not found");
	pid = fork();
	if (pid == 0)
	{
		if (s_pipex->fd_here)
		{
			if (dup2(s_pipex->fd_here, 1) < 0)
				ft_perror("Error");
		}
		else
		{
			if (dup2(s_pipex->fd_output, 1) < 0)
				ft_perror("Error");
		}
		execute_command(s_pipex, env);
	}
	waitpid(pid, NULL, 0);
	waitpid(s_pipex->pid_cmd1, NULL, 0);
}

void	change_fd(char **argv, int argc, t_struct *s_pipex)
{
	s_pipex->fd_input = open(argv[1], O_RDONLY);
	if (s_pipex->fd_input < 0)
		ft_perror("Error");
	if (dup2(s_pipex->fd_input, 0) < 0)
		ft_perror("Error");
	close(s_pipex->fd_input);
	s_pipex->fd_output = open(argv[argc - 1], \
						O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (s_pipex->fd_output < 0)
		ft_perror("Error");
	if (dup2(s_pipex->fd_output, 1) < 0)
		ft_perror("Error");
}
