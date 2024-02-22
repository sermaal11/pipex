/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:49:27 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/22 10:59:15 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
En la función ft_child_one hacemos lo siguiente:
1.	Recibimos un puntero a una estructura de tipo t_data llamada data, un
	puntero a un char llamado file, un puntero a un char llamado command y un
	puntero a un puntero de tipo char llamado env.
2.	Creamos un proceso hijo mediante la función fork.
3.	Si el proceso hijo se ha creado correctamente, abrimos el archivo file en
	modo lectura.
4.	Si el archivo no se ha abierto correctamente, llamamos a la función ft_error
	que imprime un mensaje de error y termina el programa.
5.	Redirigimos la entrada estándar al archivo file.
6.	Redirigimos la salida estándar al pipe.
7.	Cerramos el archivo file.
8.	Cerramos el pipe en modo lectura.
9.	Ejecutamos el comando con la función execve.
10.	Liberamos la memoria.
11.	Si el proceso hijo no se ha creado correctamente, llamamos a la función
	ft_error que imprime un mensaje de error y termina el programa.
*/

void	ft_child_one(t_data *data, char *file, char *command, char **env)
{
	data->pid_child_one = fork();
	if (data->pid_child_one == 0)
	{
		ft_search_valid_path(command, data);
		data->infile_fd = open(file, O_RDONLY);
		if (data->infile_fd == -1)
			ft_error("Error");
		dup2(data->infile_fd, STDIN_FILENO);
		dup2(data->pipe_fd[W], STDOUT_FILENO);
		close(data->infile_fd);
		close(data->pipe_fd[R]);
		execve(data->valid_path, data->matrix_command, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_child_one < 0)
		ft_error("Error: fork not created");
}

/*
En la función ft_child_two hacemos lo siguiente:
1.	Recibimos un puntero a una estructura de tipo t_data llamada data, un
	puntero a un char llamado file, un puntero a un char llamado command y un
	puntero a un puntero de tipo char llamado env.
2.	Creamos un proceso hijo mediante la función fork.
3.	Si el proceso hijo se ha creado correctamente, abrimos el archivo file en
	modo lectura y escritura, si el archivo no existe, lo creamos.
4.	Si el archivo no se ha abierto correctamente, llamamos a la función ft_error
	que imprime un mensaje de error y termina el programa.
5.	Redirigimos la entrada estándar al pipe.
6.	Redirigimos la salida estándar al archivo file.
7.	Cerramos el archivo file.
8.	Cerramos el pipe en modo escritura.
9.	Ejecutamos el comando con la función execve.
10.	Liberamos la memoria.
11.	Si el proceso hijo no se ha creado correctamente, llamamos a la función
	ft_error que imprime un mensaje de error y termina el programa.
*/

void	ft_child_two(t_data *data, char *file, char *command, char **env)
{
	data->pid_child_two = fork();
	if (data->pid_child_two == 0)
	{
		ft_search_valid_path(command, data);
		data->outfile_fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (data->outfile_fd == -1)
			perror("Error");
		dup2(data->pipe_fd[R], STDIN_FILENO);
		dup2(data->outfile_fd, STDOUT_FILENO);
		close(data->outfile_fd);
		close(data->pipe_fd[W]);
		execve(data->valid_path, data->matrix_command, env);
		ft_free(data);
		exit(127);
	}
	else if (data->pid_child_two < 0)
		ft_error("Error: fork not created\n");
}
