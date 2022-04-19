/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 15:32:56 by vmusunga          #+#    #+#             */
/*   Updated: 2022/04/19 16:32:32 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env, char *cmd)
{
	int x;
	int i;
	char *path;
	char **path_tab;

	x = 0;
	while (ft_strncmp(env[x], "PATH=", 5) != 0)
		x++;
	path_tab = ft_split(env[x] + 5, ':');
	i = 0;
	while (path_tab[i])
	{
		path = ft_strjoin(path_tab[i], cmd);
		if (access(path, F_OK) == 0)
		{
			printf("%s", path);
			return (path);
		}
		free(path);
		i++;
	}
	i = -1;
	while (path_tab[++i])
		free(path_tab[i]);
	free(path_tab);
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
	if (execve(path, cmd, env) == -1)
		error(4);
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
	free(path);
	return ;
}

void	error(int tag)
{
	//write(2, "Error", 5);
	printf("Error%d\n", tag);
	exit(EXIT_FAILURE);
}
