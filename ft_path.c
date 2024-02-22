/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:24:09 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/21 23:08:02 by sergio           ###   ########.fr       */
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
