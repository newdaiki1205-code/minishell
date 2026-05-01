/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:38:42 by nhamad            #+#    #+#             */
/*   Updated: 2026/03/11 14:38:47 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"
#include <errno.h>

void	first_kid(char *infile, char *cmd, t_cleanup *cl, char **envp)
{
	cl->fd_in = open(infile, O_RDONLY);
	if (cl->fd_in < 0)
		error_exit(infile, cl);
	dup2(cl->fd_in, STDIN_FILENO);
	dup2(cl->pipe_fd[1], STDOUT_FILENO);
	safe_close(&cl->fd_in);
	safe_close(&cl->pipe_fd[0]);
	safe_close(&cl->pipe_fd[1]);
	exec_cmd(cmd, cl, envp);
}

void	second_kid(char *outfile, char *cmd, t_cleanup *cl, char **envp)
{
	cl->fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cl->fd_out < 0)
		error_exit(outfile, cl);
	dup2(cl->pipe_fd[0], STDIN_FILENO);
	dup2(cl->fd_out, STDOUT_FILENO);
	safe_close(&cl->fd_out);
	safe_close(&cl->pipe_fd[0]);
	safe_close(&cl->pipe_fd[1]);
	exec_cmd(cmd, cl, envp);
}

void	cmd_not_found(char *cmd, t_cleanup *cl)
{
	write(2, cmd, ft_strlen(cmd));
	write(2, ": command not found\n", 20);
	cleanup_resources(cl);
	exit(127);
}

static void	resolve_cmd(char *cmd, t_cleanup *cl)
{
	cl->args = ft_split(cmd, ' ');
	if (!cl->args || !cl->args[0])
		cmd_not_found(cmd, cl);
}

void	exec_cmd(char *cmd, t_cleanup *cl, char **envp)
{
	resolve_cmd(cmd, cl);
	cl->path = get_cmd_path(cl->args[0], envp, cl);
	if (!cl->path)
		cmd_not_found(cmd, cl);
	execve(cl->path, cl->args, envp);
	perror(cl->args[0]);
	cleanup_resources(cl);
	if (errno == EACCES)
		exit(126);
	exit(1);
}
