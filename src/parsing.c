/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:17:54 by rsenelle          #+#    #+#             */
/*   Updated: 2022/02/20 00:58:13 by rsenelle         ###   ########.fr       */
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
		while (s_pipex->path)
			i++;
	return (i);
}

char	**put_str_to_arr(char **arr, int size, char *s)
{
	int		i;
	char	**res;

	if (arr && s)
	{
		res = malloc(sizeof(char *) * (size + 1) + 1);
		if (!res)
			return (NULL);
		i = 0;
		while (arr[i++])
			res[i] = arr[i];
		res[i] = s;
		i++;
		res[i] = NULL;
		free (arr);
		return (res);
	}
	else if (s && !arr)
	{
		if (!(res = malloc(sizeof(char *) + 1)))
			return (NULL);
		res[0] = s;
		res[1] = NULL;
		free (arr);
		return (res);
	}
	return (NULL);
}

int	check_path(char **env, t_struct *s_pipex)
{
	int		i;
	char	*temp;
	int		pos;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5) || !ft_strncmp(env[i], "PWD=", 4))
		{
			if (!ft_strncmp(env[i], "PATH=", 5))
			{
				temp = ft_strchr(env[i], '/');
				if (!temp)
					return (1);
				if (!(s_pipex->path = ft_split(temp, ':')))
					return (1);
				// return (0);
			}
			if (!ft_strncmp(env[i], "PWD=", 4))
			{
				temp = ft_strchr(env[i], '/');
				if (!temp)
					return (1);
				pos = count_path_strings(s_pipex);
				s_pipex->path = put_str_to_arr(s_pipex->path, pos, temp);
			}
		}
		i++;
	}
	return (1);
}

void	execute_command(t_struct *s_pipex, char **env)
{
	int		i;
	char	*res_path;

	i = 0;
	while (s_pipex->path[i])
	{
		res_path = ft_strjoin(s_pipex->path[i], "/");
		res_path = ft_strjoin(res_path, s_pipex->cmd1[0]);
		if (!access(res_path, F_OK))
			execve(res_path, s_pipex->cmd1, env);
		// printf("%s\n", res_path);
		i++;
	}
}

int	redirect_input_file(char **argv, t_struct *s_pipex, char **env)
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
	if (argc == 5 || argc == 3)
	{
		add_command_to_array(argv, 2, &s_pipex);
		// add_command_to_array(argv, 3, &s_pipex);
		if (check_path(env, &s_pipex))
			ft_error("No PATH");
		if (pipe(fd) == -1)
			perror("Error");
		redirect_input_file(argv, &s_pipex, env);
	}
	// char *str[n];
	// str[0] = "ls";
	// str[1] = "-l";
	// str[2] = NULL;
	// write(1,"pasha i maxim loh\n",18);
	// execve("/bin/ls", ft_split("ls", ' '), env);
}