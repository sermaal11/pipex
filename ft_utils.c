/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:10:45 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/21 18:06:37 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *msg)
{
	perror(msg);
	exit(1);
}

void	ft_free_matrix(char **sys_path)
{
	int	i;

	i = 0;
	while (sys_path[i])
	{
		free(sys_path[i]);
		sys_path[i] = NULL;
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
