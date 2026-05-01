/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:38:58 by nhamad            #+#    #+#             */
/*   Updated: 2026/03/11 14:39:04 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	free_split(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	safe_close(int *fd)
{
	if (*fd >= 0)
	{
		close(*fd);
		*fd = -1;
	}
}

void	init_cleanup(t_cleanup *cl)
{
	cl->args = NULL;
	cl->paths = NULL;
	cl->path = NULL;
	cl->tmp = NULL;
	cl->full = NULL;
	cl->pipe_fd[0] = -1;
	cl->pipe_fd[1] = -1;
	cl->fd_in = -1;
	cl->fd_out = -1;
}

void	cleanup_resources(t_cleanup *cl)
{
	free(cl->path);
	cl->path = NULL;
	free(cl->tmp);
	cl->tmp = NULL;
	free(cl->full);
	cl->full = NULL;
	free_split(cl->args);
	cl->args = NULL;
	free_split(cl->paths);
	cl->paths = NULL;
	safe_close(&cl->fd_in);
	safe_close(&cl->fd_out);
	safe_close(&cl->pipe_fd[0]);
	safe_close(&cl->pipe_fd[1]);
}

void	error_exit(char *msg, t_cleanup *cl)
{
	perror(msg);
	cleanup_resources(cl);
	exit(1);
}
