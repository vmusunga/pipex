/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vic <vic@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:50:25 by vmusunga          #+#    #+#             */
/*   Updated: 2022/04/20 18:59:06 by vic              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <string.h>

typedef struct	s_utils
{
	char **path_tab;
	int *end;
}				t_utils;

/// LIBFT
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);

/// UTILS
char	*get_path(char **env, char *cmd);
void	executer(char *argv, char **env);
void	error(char *msg);

#endif