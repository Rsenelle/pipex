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

void	add_command_to_array(char **argv, int i, t_struct *s_pipex)
{
	if (i == 2)
	{
		if(!(s_pipex->cmd = ft_split(argv[i], ' ')))
			ft_error("Split error 1");
	}
	else if (i == 3)
	{
		if(!(s_pipex->cmd2 = ft_split(argv[i], ' ')))
			ft_error("Split error");
	}
}

int	count_path_strings(t_struct *s_pipex)
{
	int	i;
	
	i = 0;
	if (s_pipex->path)
		while (s_pipex->path[i])
			i++;
	return (i);
}

int	check_path(char **env, t_struct *s_pipex)
{
	int		i;
	char	*temp;
	int		size;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
		{
			temp = ft_strchr(env[i], '/');
			if (!temp)
				return (1);
			if (!(s_pipex->path = ft_split(temp, ':')))
				return (1);
		}
		i++;
	}
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD=", 4))
		{
			temp = ft_strchr(env[i], '/');
			if (!temp)
				return (1);
			size = count_path_strings(s_pipex);
			s_pipex->path = add_str_to_arr(s_pipex->path, size, temp);
			if (!s_pipex->path)
				return (1);
		}
		i++;
	}
	return (0);
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
		int l = access(res_path, 0|1);
		if (!l)
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
		if ((fd = open(argv[1], O_RDONLY)) < 0)
		{
			perror("Error2");
			exit (1);
		}
		if (dup2(fd, 0) == -1)
			perror("Error5");
		close(fd);
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
//	pid_t	pid;

//	pid = fork();
//	if (pid == 0)
//	{
		if ((fd = open(argv[4], O_CREAT|O_WRONLY|O_TRUNC, 0777)) < 0)
		{
			printf("%s", argv[4]);
			perror("Error1");
			exit (1);
		}
		if (dup2(s_pipex->fd[0], 0) == -1)
			perror("Error3");
		if (dup2(fd, 1) == -1)
			perror("Error4");
		close(fd);
		close(s_pipex->fd[0]);
		close(s_pipex->fd[1]);
		s_pipex->cmd[0] = ft_strdup("cat");
		execute_command(s_pipex, env);
//	}
//	waitpid(pid, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int			i;
	t_struct	s_pipex;
	// char		*s;

	i = 0;
	// init_struct(&s_pipex);
	if (argc == 5 || argc == 3)
	{
		add_command_to_array(argv, 2, &s_pipex);
		// add_command_to_array(argv, 3, &s_pipex);
		if (check_path(env, &s_pipex))
			ft_error("No PATH");
		if (pipe(s_pipex.fd) == -1)
			perror("Error");
		left_redirect_input_file(argv, &s_pipex, env);
		free_buf(s_pipex.cmd);
		right_redirect_output_file(argv, &s_pipex, env);
		// free_buf(s_pipex.cmd);
		close(s_pipex.fd[1]);
		close(s_pipex.fd[0]);
		// s = NULL;
		// read(s_pipex.fd[0], s, 2);
		// write(1, s, 2);
	}
	
	// char *str[n]
	// str[0] = "ls";
	// str[1] = "-l";
	// str[2] = NULL;
	// write(1,"pasha i maxim loh\n",18);
	// execve("/bin/ls", ft_split("ls", ' '), env);
}
