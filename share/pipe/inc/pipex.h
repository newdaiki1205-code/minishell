/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhamad <nhamad@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:39:21 by nhamad            #+#    #+#             */
/*   Updated: 2026/03/11 14:39:25 by nhamad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cleanup
{
	char	**args;
	char	**paths;
	char	*path;
	char	*tmp;
	char	*full;
	int		pipe_fd[2];
	int		fd_in;
	int		fd_out;
}			t_cleanup;

void		init_cleanup(t_cleanup *cl);
void		cleanup_resources(t_cleanup *cl);
void		safe_close(int *fd);
void		first_kid(char *infile, char *cmd, t_cleanup *cl, char **envp);
void		second_kid(char *outfile, char *cmd, t_cleanup *cl, char **envp);
void		exec_cmd(char *cmd, t_cleanup *cl, char **envp);
char		*get_cmd_path(char *cmd, char **envp, t_cleanup *cl);
char		*get_path_value(char **envp);
void		free_split(char **arr);
void		error_exit(char *msg, t_cleanup *cl);
void		cmd_not_found(char *cmd, t_cleanup *cl);

#endif
