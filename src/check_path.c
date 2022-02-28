//
// Created by Romaine Senelle on 2/28/22.
//
#include "../include/pipex.h"

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
