/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:38:18 by nhamad            #+#    #+#             */
/*   Updated: 2026/03/11 14:38:25 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*get_path_value(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*build_path(char *dir, char *cmd, t_cleanup *cl)
{
	cl->tmp = ft_strjoin(dir, "/");
	if (!cl->tmp)
		return (NULL);
	cl->full = ft_strjoin(cl->tmp, cmd);
	free(cl->tmp);
	cl->tmp = NULL;
	if (!cl->full)
		return (NULL);
	return (cl->full);
}

static char	*find_in_paths(char *cmd, t_cleanup *cl)
{
	int	i;

	i = 0;
	while (cl->paths[i])
	{
		cl->full = build_path(cl->paths[i], cmd, cl);
		if (!cl->full)
			return (NULL);
		if (access(cl->full, X_OK) == 0)
			return (cl->full);
		free(cl->full);
		cl->full = NULL;
		i++;
	}
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp, t_cleanup *cl)
{
	char	*path_value;

	if (ft_strchr(cmd, '/') && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	path_value = get_path_value(envp);
	if (!path_value)
		return (NULL);
	cl->paths = ft_split(path_value, ':');
	if (!cl->paths)
		return (NULL);
	cl->path = find_in_paths(cmd, cl);
	free_split(cl->paths);
	cl->paths = NULL;
	cl->full = NULL;
	return (cl->path);
}
