/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:44:21 by sergio            #+#    #+#             */
/*   Updated: 2024/03/06 11:44:27 by smarin-a         ###   ########.fr       */
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

void	ft_search_valid_path(char *command, t_data *d)
{
	int		i;
	char	*barra;

	d->matrix_cmd = ft_split(command, ' ');
	if (access(*d->matrix_cmd, X_OK) == 0 && ft_strrchr(*d->matrix_cmd, '/'))
	{
		d->valid_path = ft_strdup(d->matrix_cmd[0]);
		return ;
	}
	if (access(*d->matrix_cmd, X_OK) != 0 && ft_strrchr(*d->matrix_cmd, '/'))
		ft_error("Error", 127);
	barra = ft_strdup("/");
	d->temp_path = ft_strjoin(barra, d->matrix_cmd[0]);
	i = 0;
	while (d->matrix_path[i])
	{
		d->matrix_joined_path = ft_strjoin(d->matrix_path[i++], d->temp_path);
		if (access(d->matrix_joined_path, X_OK) == 0)
		{
			d->valid_path = d->matrix_joined_path;
			return (free(d->temp_path));
		}
		free(d->matrix_joined_path);
	}
	(ft_error("Command not found", 1), free(d->temp_path));
}
