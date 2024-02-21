/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:10:45 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/21 20:54:32 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(1);
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
	pipe(data->pipe_fd);
	if (pipe(data->pipe_fd) == -1)
		perror("Error: pipe not created\n");
}

void	ft_free(t_data *data)
{
	free(data->valid_path);
	ft_free_matrix(data->matrix_command);
	free(data->matrix_command);
	ft_free_matrix(data->matrix_path);
	free(data->matrix_path);
}

void	ft_close_n_wait(t_data *data)
{
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	waitpid(data->pid_child_one, NULL, 0);
	waitpid(data->pid_child_two, NULL, 0);
}
