/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:36:14 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/22 23:33:57 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_child_one(t_data *data, char *file, char *cmd, char **env)
{
	data->pid_child_one = fork();
	if (data->pid_child_one == 0)
	{
		ft_search_valid_path(cmd, data);
		data->infile_fd = open(file, O_RDONLY);
		if (data->infile_fd == -1)
			ft_error("Error", 1);
		dup2(data->infile_fd, STDIN_FILENO);
		dup2(data->pipe_fd[W], STDOUT_FILENO);
		close(data->infile_fd);
		close(data->pipe_fd[R]);
		execve(data->valid_path, data->matrix_cmd, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_child_one < 0)
		ft_error("Error: fork not created", 1);
}

void	ft_child_last(t_data *data, char *file, char *cmd, char **env)
{
	data->pid_child_last = fork();
	if (data->pid_child_last == 0)
	{
		ft_search_valid_path(cmd, data);
		data->outfile_fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (data->outfile_fd == -1)
			perror("Error");
		dup2(data->pipe_fd[R], STDIN_FILENO);
		dup2(data->outfile_fd, STDOUT_FILENO);
		close(data->outfile_fd);
		close(data->pipe_fd[W]);
		execve(data->valid_path, data->matrix_cmd, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_child_last < 0)
		ft_error("Error: fork not created", 1);
}

// void	ft_chiled_middle(t_data *data, int iter, char *cmd, char **env)
// {
	
// }