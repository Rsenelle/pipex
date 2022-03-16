/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:02:32 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/11 15:07:47 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	fork_main(t_struct *s_pipex, char **env)
{
	s_pipex->pid_cmd1 = fork();
	if (s_pipex->pid_cmd1 < 0)
		ft_perror(NULL);
	if (s_pipex->pid_cmd1 == 0)
		child_process(s_pipex, env);
	parent_process(s_pipex);
}

int	main(int argc, char **argv, char **env)
{
	t_struct	s_pipex;
	int			i;

	i = 2;
	if (argc <= 4)
		ft_error("Wrong arguments");
	init_struct(&s_pipex);
	s_pipex.flag = check_heredoc(argv, argc, &s_pipex);
	check_path(env, &s_pipex);
	if (s_pipex.flag != 0)
		change_fd(argv, argc, &s_pipex);
	else
		i++;
	while (i < argc - 2)
	{
		add_command_to_array(argv[i], &s_pipex);
		if (!s_pipex.cmd[0])
			ft_error("command not found");
		if (pipe(s_pipex.fd) < 0)
			perror("Error");
		fork_main(&s_pipex, env);
		i++;
	}
	last_command(&s_pipex, argv, argc, env);
}
