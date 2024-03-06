/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:20:39 by sergio            #+#    #+#             */
/*   Updated: 2024/03/06 11:44:52 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg, int n_error)
{
	perror(msg);
	exit(n_error);
}

void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		matrix[i] = NULL;
		i++;
	}
}

void	ft_pipe(t_data *data)
{
	if (pipe(data->pipe_fd) == -1)
		perror("Error: pipe not created\n");
}

void	ft_free(t_data *data)
{
	free(data->valid_path);
	ft_free_matrix(data->matrix_cmd);
	free(data->matrix_cmd);
	ft_free_matrix(data->matrix_path);
	free(data->matrix_path);
	free(data->pid_childs);
}

int	ft_close_n_wait(t_data *data)
{
	int	status;
	int	i;

	i = 0;
	close(data->pipe_fd[R]);
	close(data->pipe_fd[W]);
	while (data->pid_childs[i] && i + 1 < data->index_pid)
		waitpid(data->pid_childs[i++], NULL, 0);
	waitpid(data->pid_child_last, &status, 0);
	return (status);
}
