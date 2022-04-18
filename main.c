/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:15:19 by vmusunga          #+#    #+#             */
/*   Updated: 2022/04/18 18:14:36 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	int x;
	char *path_raw;
	char **path_tab;

	x = 0;
	while (env[x])
	{
		if (ft_strncmp(env[x], "PATH=", 5) == 0)
		{
			path_raw = strlcpy(env[x] + 5) //ca marche ca? (skip "PATH=")
			break;
		}
		x++;
	}
	if (!path_raw)
		return (NULL);
	path_tab = ft_split(path_raw, ':');
	free(path_raw);
	return (path_tab);
}

void	command_handle(char *cmd); // cat -e

/// stdin + cmd1 --> end[1]
void	child_prcess(char **argv, t_list *utils)
{
	int file1;

	file1 = open(argv[1], O_RDONLY); //input = path
	exec command1
	save to utils->end[1];
	close(fd);
}

/// end[1](read) --> end[0](write) | end[0] (=input) + cmd2 --> stdout
void	parent_process(char **argv, t_list *utils)
{
	file1 = open(utils->end[1], O_RDONLY);

	file2 = open(argv[4], O_WRONLY);
	exec command2
	file2 = stdout
}

int	main(int ac, char **argv, char **env)
{
	get_path(env);
	child_process(argv);
}