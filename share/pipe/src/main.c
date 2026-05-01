/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:37:41 by nhamad            #+#    #+#             */
/*   Updated: 2026/03/11 14:37:49 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

static void	run_child(char **argv, int argc, int i, int prev_read, int *pipe_fd,
		char **envp)
{
	t_cleanup	cl;
	int			fd;

	init_cleanup(&cl);
	if (i == 0)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			error_exit(argv[1], &cl);
		dup2(fd, STDIN_FILENO);
		safe_close(&fd);
	}
	else
		dup2(prev_read, STDIN_FILENO);
	if (i == argc - 4)
	{
		fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd < 0)
			error_exit(argv[argc - 1], &cl);
		dup2(fd, STDOUT_FILENO);
		safe_close(&fd);
	}
	else
		dup2(pipe_fd[1], STDOUT_FILENO);
	safe_close(&prev_read);
	safe_close(&pipe_fd[0]);
	safe_close(&pipe_fd[1]);
	exec_cmd(argv[i + 2], &cl, envp);
}

static int	wait_children(pid_t *pids, int count)
{
	int	status;
	int	last_status;
	int	i;

	last_status = 1;
	i = 0;
	while (i < count)
	{
		if (waitpid(pids[i], &status, 0) < 0)
			return (1);
		if (i == count - 1)
			last_status = status;
		i++;
	}
	if (WIFEXITED(last_status))
		return (WEXITSTATUS(last_status));
	if (WIFSIGNALED(last_status))
		return (128 + WTERMSIG(last_status));
	return (1);
}

static int	create_pipeline(int argc, char **argv, char **envp)
{
	pid_t	*pids;
	int		pipe_fd[2];
	int		prev_read;
	int		i;

	pids = malloc(sizeof(pid_t) * (argc - 3));
	if (!pids)
		return (1);
	prev_read = -1;
	i = 0;
	while (i < argc - 3)
	{
		pipe_fd[0] = -1;
		pipe_fd[1] = -1;
		if (i < argc - 4 && pipe(pipe_fd) < 0)
			return (free(pids), 1);
		pids[i] = fork();
		if (pids[i] < 0)
			return (free(pids), 1);
		if (pids[i] == 0)
			run_child(argv, argc, i, prev_read, pipe_fd, envp);
		safe_close(&prev_read);
		safe_close(&pipe_fd[1]);
		prev_read = pipe_fd[0];
		i++;
	}
	safe_close(&prev_read);
	i = wait_children(pids, argc - 3);
	free(pids);
	return (i);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
	{
		write(2, "Usage: ./pipex file1 cmd1 ... cmdN file2\n", 40);
		return (1);
	}
	return (create_pipeline(argc, argv, envp));
}
