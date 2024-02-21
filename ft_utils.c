/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:10:45 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/21 15:29:48 by smarin-a         ###   ########.fr       */
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

void ft_pipe(t_data *data)
{
	pipe(data->fd);
	if (pipe(data->fd) == -1)
		perror("Error: pipe not created\n");
}