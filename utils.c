/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:56 by vmusunga          #+#    #+#             */
/*   Updated: 2022/04/25 17:21:46 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env, char *cmd)
{
	int		x;
	char	*tmp;
	char	*path;
	char	**path_tab;

	x = 0;
	while (ft_strncmp(env[x], "PATH=", 5) != 0)
		x++;
	path_tab = ft_split(env[x] + 5, ':');
	x = 0;
	while (path_tab[x])
	{
		tmp = ft_strjoin(path_tab[x], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		x++;
	}
	x = -1;
	while (path_tab[++x])
		free(path_tab[x]);
	free(path_tab);
	return (NULL);
}

int	executer(char *argv, char **env)
{
	int		i;
	char	*path;
	char	**cmd;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = get_path(env, cmd[0]);
	execve(path, cmd, env);
	if (!path)
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		return (-1);
	}
	else
		free(path);
	return (0);
}

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(EXIT_SUCCESS);
}
