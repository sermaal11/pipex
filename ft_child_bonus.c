/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:40:06 by sergio            #+#    #+#             */
/*   Updated: 2024/02/23 15:09:26 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(t_data *data, char *file, char *command, char **env)
{
	data->pid_child_one = fork();
	if (data->pid_child_one == 0)
	{
		ft_search_valid_path(command, data);
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

void	ft_child_middle(t_data *data, char *command, char **env)
{
	data->pid_child_middle = fork();
	if (data->pid_child_middle == 0)
	{
		ft_search_valid_path(command, data);
		dup2(data->tmp_fd, STDIN_FILENO);
		dup2(data->pipe_fd[W], STDOUT_FILENO);
		close(data->tmp_fd);
		close(data->pipe_fd[W]);
		close(data->pipe_fd[R]);
		execve(data->valid_path, data->matrix_cmd, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_child_middle < 0)
		ft_error("Error: fork not created", 1);
}

void	ft_child_last(t_data *data, char *file, char *command, char **env)
{
	data->pid_child_last = fork();
	if (data->pid_child_last == 0)
	{
		ft_search_valid_path(command, data);
		data->outfile_fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (data->outfile_fd == -1)
			perror("Error");
		dup2(data->tmp_fd, STDIN_FILENO);
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