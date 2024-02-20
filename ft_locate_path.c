/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_locate_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:24:09 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/20 18:26:59 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_locate_path(char **env, t_data *data)
{
	int i;

	i = 0;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			data->matrix_path = (ft_split(env[i], ':'));
	}
	i = -1;
	while (data->matrix_path[0][++i + 5])
		data->matrix_path[0][i] = data->matrix_path[0][i + 5];
	while (data->matrix_path[0][i])
		data->matrix_path[0][i++] = '\0';
}

void ft_free_path(char **sys_path)
{
	int i;

	i = 0;
	while (sys_path[i])
	{
		free(sys_path[i]);
		sys_path[i] = NULL;
		i++;
	}
}
