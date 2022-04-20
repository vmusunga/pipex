/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:56 by vmusunga          #+#    #+#             */
/*   Updated: 2022/04/20 19:08:39 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env, char *cmd)
{
	int x;
	char *tmp;
	char *path;
	char **path_tab;

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
	// printf("%s\n", path);
	if (!path)
		error("Path not found");
	return (0);
}

void	executer(char *argv, char **env) //if (!path)
{
	int i;
	char *path;
	char **cmd;

	i = -1;
	cmd = ft_split(argv, ' ');
	path = get_path(env, cmd[0]);
	execve(path, cmd, env);
	if (!path)
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
	free(path);
	return ;
}

void	error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	// printf("Error%d\n", tag);
	exit(EXIT_FAILURE);
}
