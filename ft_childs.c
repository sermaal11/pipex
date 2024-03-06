/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:49:27 by smarin-a          #+#    #+#             */
/*   Updated: 2024/03/06 11:44:19 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child_one(t_data *data, char *file, char *command, char **env)
{
	if (pipe(data->pipe_fd) == -1)
		perror("Error: pipe not created\n");
	data->pid_child_one = fork();
	if (data->pid_child_one == 0)
	{
		close(data->pipe_fd[R]);
		ft_search_valid_path(command, data);
		data->infile_fd = open(file, O_RDONLY);
		if (data->infile_fd == -1)
		{
			close(data->pipe_fd[R]);
			ft_error("Error", 1);
		}
		dup2(data->infile_fd, STDIN_FILENO);
		dup2(data->pipe_fd[W], STDOUT_FILENO);
		close(data->infile_fd);
		close(data->pipe_fd[W]);
		execve(data->valid_path, data->matrix_cmd, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_child_one < 0)
		ft_error("Error: fork not created", 1);
}

void	ft_child_two(t_data *data, char *file, char *command, char **env)
{
	data->pid_child_two = fork();
	if (data->pid_child_two == 0)
	{
		ft_search_valid_path(command, data);
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
	else if (data->pid_child_two < 0)
		ft_error("Error: fork not created", 1);
}
