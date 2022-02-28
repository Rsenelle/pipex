/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:17:54 by rsenelle          #+#    #+#             */
/*   Updated: 2022/02/27 14:24:44 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	add_command_to_array(char *argv, t_struct *s_pipex)
{
	if(!(s_pipex->cmd = ft_split(argv, ' ')))
			ft_error("Split error");
}

void	execute_command(t_struct *s_pipex, char **env)
{
	int		i;
	char	*res_path;

	i = 0;

	while (s_pipex->path[i])
	{
		res_path = ft_strjoin(s_pipex->path[i], "/");
		res_path = ft_strjoin(res_path, s_pipex->cmd[0]);
		if (!access(res_path, 0|1);)
			if (execve(res_path, s_pipex->cmd, env))
				perror("Error7");
		i++;
	}
}

int	left_redirect_input_file(char **argv, t_struct *s_pipex, char **env)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if ((s_pipex->fd_input = open(argv[1], O_RDONLY)) < 0)
		{
			perror("Error2");
			exit (1);
		}
		if (dup2(s_pipex->fd_input, 0) == -1)
			perror("Error5");
		close(s_pipex->fd_input);
		if (dup2(s_pipex->fd[1], 1) == -1)
			perror("Error6");
		close (s_pipex->fd[1]);
		close (s_pipex->fd[0]);
		execute_command(s_pipex, env);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

int	right_redirect_output_file(char **argv, t_struct *s_pipex,char **env)
{
	int		fd;
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		if ((s_pipex->fd_output = open(argv[4], O_CREAT|O_WRONLY|O_TRUNC, 0777)) < 0)
		{
			printf("%s", argv[4]);
			perror("Error1");
			exit (1);
		}
		if (dup2(s_pipex->fd[0], 0) == -1)
			perror("Error3");
		if (dup2(s_pipex->fd_output, 1) == -1)
			perror("Error4");
		close(s_pipex->fd_output);
		close(s_pipex->fd[0]);
		close(s_pipex->fd[1]);
		s_pipex->cmd[0] = ft_strdup("cat");
		execute_command(s_pipex, env);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int i;
	t_struct s_pipex;
	// char		*s;

	// init_struct(&s_pipex);
	if (argc > 3)
	{

		i = 2;
		while (i < argc)
		{
			add_command_to_array(argv[i], &s_pipex);
			if (check_path(env, &s_pipex))
				ft_error(NULL);
			if (pipe(s_pipex.fd) == -1)
				perror("Error");
			left_redirect_input_file(argv, &s_pipex, env);
			free_buf(s_pipex.cmd);
			right_redirect_output_file(argv, &s_pipex, env);
			// free_buf(s_pipex.cmd);
			close(s_pipex.fd[1]);
			close(s_pipex.fd[0]);
			i++;
		}
	}
}
