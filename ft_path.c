/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:24:09 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/21 19:17:01 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_split_path(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "PATH=", 5))
			data->matrix_path = ft_split(env[i] + 5, ':');
	}
}

void	ft_search_valid_path(char *command, t_data *data)
{
	int		i;
	char	*temp_path;

	data->matrix_command = ft_split(command, ' ');
	if (access(data->matrix_command[0], X_OK) == 0)
	{
		data->valid_path = ft_strdup(data->matrix_command[0]);
		return ;
	}
	temp_path = ft_strjoin("/", data->matrix_command[0]);
	i = 0;
	while (data->matrix_path[i])
	{
		data->matrix_joined_path = ft_strjoin(data->matrix_path[i], temp_path);
		if (access(data->matrix_joined_path, X_OK) == 0)
		{
			data->valid_path = data->matrix_joined_path;
			free(temp_path);
			return ;
		}
		free(data->matrix_joined_path);
		i++;
	}
	free(temp_path);
}
