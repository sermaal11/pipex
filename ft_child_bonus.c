/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 12:40:06 by sergio            #+#    #+#             */
/*   Updated: 2024/03/06 11:44:08 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_foock(t_data *data, int argc, char **argv, char **env)
{
	if (data->here_doc == 1)
		ft_child_one(data, ".here_doc", argv[3], env);
	else
		ft_child_one(data, argv[1], argv[2], env);
	data->index_pid++;
	data->tmp_fd = data->pipe_fd[R];
	close(data->pipe_fd[W]);
	while (data->num_cmd_middle != 0)
	{
		ft_pipe(data);
		ft_child_middle(data, argv[data->index_cmd_middle++], env);
		close(data->pipe_fd[W]);
		data->index_pid++;
		data->tmp_fd = data->pipe_fd[R];
		data->num_cmd_middle--;
	}
	ft_child_last(data, argv[argc - 1], argv[argc - 2], env);
}

void	ft_child_one(t_data *data, char *file, char *command, char **env)
{
	if (pipe(data->pipe_fd) == -1)
		perror("Error: pipe not created");
	data->pid_childs[data->index_pid] = fork();
	if (data->pid_childs[data->index_pid] == 0)
	{
		close(data->pipe_fd[R]);
		ft_search_valid_path(command, data);
		data->infile_fd = open(file, O_RDONLY);
		if (data->infile_fd == -1)
			ft_error("Error", 1);
		dup2(data->infile_fd, STDIN_FILENO);
		dup2(data->pipe_fd[W], STDOUT_FILENO);
		close(data->infile_fd);
		close(data->pipe_fd[W]);
		execve(data->valid_path, data->matrix_cmd, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_childs[data->index_pid] < 0)
		ft_error("Error: fork not created", 1);
}

void	ft_child_middle(t_data *data, char *command, char **env)
{
	data->pid_childs[data->index_pid] = fork();
	if (data->pid_childs[data->index_pid] == 0)
	{
		close(data->pipe_fd[R]);
		ft_search_valid_path(command, data);
		dup2(data->tmp_fd, STDIN_FILENO);
		dup2(data->pipe_fd[W], STDOUT_FILENO);
		close(data->tmp_fd);
		close(data->pipe_fd[W]);
		execve(data->valid_path, data->matrix_cmd, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_childs[data->index_pid] < 0)
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
		{
			close(data->tmp_fd);
			perror("Error");
		}
		dup2(data->tmp_fd, STDIN_FILENO);
		dup2(data->outfile_fd, STDOUT_FILENO);
		close(data->outfile_fd);
		close(data->tmp_fd);
		execve(data->valid_path, data->matrix_cmd, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_child_last < 0)
		ft_error("Error: fork not created", 1);
}
