/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_heredoc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:06:38 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/09 20:45:51 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	child_heredoc(int *fd, char *limiter)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (ft_strncmp(line, limiter, ft_strlen(line) - 1) == 0 && \
			ft_strlen(line) == ft_strlen(limiter))
		{
			close(fd[0]);
			close(fd[1]);
			exit(0);
		}
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		line = get_next_line(0);
	}
}

void	heredoc_main(char *limiter)
{
	int	fd[2];
	int	pid;

	if (pipe(fd) < 0)
		ft_perror("Error");
	pid = fork();
	if (pid < 0)
		ft_perror("Error");
	if (pid == 0)
	{
		child_heredoc(fd, limiter);
	}
	if (dup2(fd[0], 0) == -1)
		ft_perror(NULL);
	wait(0);
	close(fd[1]);
	close(fd[0]);
}

void	heredoc(char **argv, int argc, t_struct *s_pipex)
{
	s_pipex->fd_here = open(argv[argc - 1], O_CREAT | O_RDWR | O_APPEND, 0777);
	if (s_pipex->fd_here < 0)
		ft_perror("Error");
	heredoc_main(argv[2]);
}

int	check_heredoc(char **argv, int argc, t_struct *s_pipex)
{
	if (!ft_strncmp (argv[1], "here_doc", 8) && ft_strlen(argv[1]) == 8)
	{
		if (argc == 6)
			heredoc(argv, argc, s_pipex);
		else
			ft_error("Wrong arguments");
	}
	else
		return (1);
	return (0);
}
