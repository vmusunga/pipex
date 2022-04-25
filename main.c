/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:15:19 by vmusunga          #+#    #+#             */
/*   Updated: 2022/04/25 14:23:07 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/// 2 unknown cmds = 2 error msgs

static int	child_process(char **argv, char **env, int *fd)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 == -1)
		error("File1 not found");
	dup2(file1, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	executer(argv[2], env);
	close(file1);
	return (0);
}

static int	parent_process(char **argv, char **env, int *fd)
{
	int	file2;

	file2 = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (file2 == -1)
		error("File2 not found");
	dup2(fd[0], STDIN_FILENO);
	dup2(file2, STDOUT_FILENO);
	close(fd[1]);
	executer(argv[3], env);
	close(file2);
	return (0);
}

int	main(int ac, char **argv, char **env)
{
	int		fd[2];
	pid_t	pid1;

	if (ac != 5)
		error("Wrong number of arguments");
	if (pipe(fd) == -1)
		error("Pipe error");
	pid1 = fork();
	if (pid1 == -1)
		error("Fork error");
	if (pid1 == 0)
	{
		if (!child_process(argv, env, fd))
			error("Command not found");
	}
	waitpid(pid1, NULL, 0);
	parent_process(argv, env, fd);
	return (0);
}
