/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmusunga <vmusunga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:50:25 by vmusunga          #+#    #+#             */
/*   Updated: 2022/04/18 17:52:42 by vmusunga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

typedef struct	s_utils
{
	char **path_tab;
	int *end;
}				t_utils;

/// LIBFT
int		ft_strncmp(const char *s1, const char *s2, size_t len);
char	**ft_split(char const *s, char c);

#endif