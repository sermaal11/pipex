/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:44:21 by sergio            #+#    #+#             */
/*   Updated: 2024/03/05 11:31:27 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
En la función ft_split_path hacemos lo siguiente:
1.	Recibimos un puntero a una estructura de tipo t_data llamada data y un
	puntero a un puntero de tipo char llamado env.
2.	Declaramos una variable de tipo entero llamada i e inicializamos en 0.
3.	Recorremos el puntero env, si encontramos la variable de entorno PATH,
	almacenamos en la estructura data la variable PATH sin el prefijo "PATH=".
*/

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

/*
En la función ft_search_valid_path hacemos lo siguiente:
1.	Recibimos un puntero a un char llamado command y un puntero a una estructura
	de tipo t_data llamada data.
2.	Declaramos una variable de tipo entero llamada i.
3.	Declaramos un puntero a un char llamado temp_path.
4.	Asignamos a la estructura data la matriz de comandos que se obtiene de
	separar el comando por espacios.
5.	Comprobamos si el comando se encuentra en el directorio actual, si es así,
	lo asignamos a la estructura data y retornamos.
6.	Concatenamos el comando con el prefijo "/" y lo asignamos a la variable
	temp_path.
7.	Recorremos la matriz de rutas, si encontramos una ruta válida, la asignamos
	a la estructura data y retornamos.
8.	Liberamos la variable temp_path.
*/

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
