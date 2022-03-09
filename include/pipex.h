/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsenelle <rsenelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:18:36 by rsenelle          #+#    #+#             */
/*   Updated: 2022/03/09 20:28:28 by rsenelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include "../libft/libft.h"

# define BUFFER_SIZE 1

typedef struct s_pipex
{
	char	**cmd;
	char	**path;
	int		fd[2];
	int		fd_input;
	int		fd_output;
	int		flag;
	int		fd_here;
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
int		check_heredoc(char **argv, int argc, t_struct *s_pipex);
char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		is_has_linebreak(char *str);
char	*trim_linebreak(char *str);
int		check_reading(int *read_sym, char *buff);
void	free_ost(char **ost);

#endif