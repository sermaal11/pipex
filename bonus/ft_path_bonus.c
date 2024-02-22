/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 17:33:09 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/22 23:33:27 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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
void	ft_search_valid_path(char *command, t_data *d)
{
	int		i;

	d->matrix_cmd = ft_split(command, ' ');
	if (access(*d->matrix_cmd, X_OK) == 0 && **d->matrix_cmd == '/')
	{
		d->valid_path = ft_strdup(d->matrix_cmd[0]);
		return ;
	}
	if (access(*d->matrix_cmd, X_OK) != 0 && ft_strrchr(*d->matrix_cmd, '/'))
		ft_error("Error", 127);
	d->temp_path = ft_strjoin("/", d->matrix_cmd[0]);
	i = 0;
	while (d->matrix_path[i])
	{
		d->matrix_joined_path = ft_strjoin(d->matrix_path[i++], d->temp_path);
		if (access(d->matrix_joined_path, X_OK) == 0)
		{
			d->valid_path = d->matrix_joined_path;
			free(d->temp_path);
			return ;
		}
		free(d->matrix_joined_path);
	}
	ft_error("Command not found", 1);
	free(d->temp_path);
}