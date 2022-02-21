/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:17:54 by rsenelle          #+#    #+#             */
/*   Updated: 2022/02/20 19:05:40 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	add_command_to_array(char **argv, int i, t_struct *s_pipex)
{
	if (i == 2)
	{
		if(!(s_pipex->cmd1 = ft_split(argv[i], ' ')))
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
		// if (dup2(fd[1], 1) == -1)
		// perror("Error");
	while (s_pipex->path[i])
	{
		res_path = ft_strjoin(s_pipex->path[i], "/");
		res_path = ft_strjoin(res_path, s_pipex->cmd1[0]);
		if (!access(res_path, F_OK))
			if (execve(res_path, s_pipex->cmd1, env))
				perror("Error");
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
			perror("Error");
			exit (1);
		}
		if (dup2(fd, 0) == -1)
			perror("Error");
		close(fd);
		execute_command(s_pipex, env);
	}
	waitpid(pid, NULL, 0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	int			i;
	t_struct	s_pipex;
	int			fd[2];

	i = 0;
	// init_struct(&s_pipex);
	if (argc == 5)
	{
		add_command_to_array(argv, 2, &s_pipex);
		// add_command_to_array(argv, 3, &s_pipex);
		if (check_path(env, &s_pipex))
			ft_error("No PATH");
		if (pipe(fd) == -1)
			perror("Error");
		left_redirect_input_file(argv, &s_pipex, env);

	}
	
	// char *str[n];
	// str[0] = "ls";
	// str[1] = "-l";
	// str[2] = NULL;
	// write(1,"pasha i maxim loh\n",18);
	// execve("/bin/ls", ft_split("ls", ' '), env);
}
