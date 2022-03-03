/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:18:36 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/03 20:00:47 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "../libft/libft.h"

typedef struct s_pipex
{
	char	**cmd;
	char	**path;
	int		fd[2];
	int		fd_input;
	int		fd_output;
}			t_struct;

void	ft_error(char *s);
void	add_command_to_array(char *argv, t_struct *s_pipex);
void	init_struct(t_struct *s_pipex);
int		check_path(char **env, t_struct *s_pipex);
void	execute_command(t_struct *s_pipex, char **env);
void	free_buf(char **buf);
void	ft_error(char *s);
void	ft_perror(char *s);
void	add_command_to_array(char *argv, t_struct *s_pipex);

#endif