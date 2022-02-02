/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:18:36 by rsenelle          #+#    #+#             */
/*   Updated: 2022/02/02 19:36:42 by rsenelle         ###   ########.fr       */
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
	char	**cmd1;
	char	**cmd2;
	char	**path;
}			t_struct;

void	ft_error(char *s);
void	add_command_to_array(char **argv, int i, t_struct *s_pipex);
int		check_space(char *s);
void	init_struct(t_struct *s_pipex);
int		check_path(char **env, t_struct *s_pipex);
int		redirect_input_file(char **argv, t_struct *s_pipex, char **env);
void	execute_command(t_struct *s_pipex, char **env);

#endif