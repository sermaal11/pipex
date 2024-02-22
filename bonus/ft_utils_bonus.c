/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 22:58:38 by sergio            #+#    #+#             */
/*   Updated: 2024/02/22 23:31:02 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
En la función ft_error hacemos lo siguiente:
1.	Recibimos un puntero a un char llamado msg.
2.	Llamamos a la función perror que imprime el mensaje de error.
3.	Terminamos el programa.
*/

void	ft_error(char *msg, int n_error)
{
	perror(msg);
	exit(n_error);
}

/*
En la función ft_free_matrix hacemos lo siguiente:
1.	Recibimos un puntero a un puntero de tipo char llamado matrix.
2.	Declaramos una variable de tipo entero llamada i e inicializamos en 0.
3.	Si la matriz no existe, retornamos.
4.	Recorremos la matriz, liberamos la memoria y asignamos NULL.
*/

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

/*
En la función ft_pipe hacemos lo siguiente:
1.	Recibimos un puntero a una estructura de tipo t_data llamada data.
2.	Creamos un pipe.
3.	Si el pipe no se ha creado correctamente, llamamos a la función perror que
	imprime un mensaje de error.
*/

void	ft_pipe(t_data *data)
{
	pipe(data->pipe_fd);
	if (pipe(data->pipe_fd) == -1)
		perror("Error: pipe not created\n");
}

/*
En la función ft_free hacemos lo siguiente:
1.	Recibimos un puntero a una estructura de tipo t_data llamada data.
2.	Liberamos la memoria de la variable valid_path.
3.	Liberamos la memoria de la matriz de comandos.
4.	Liberamos la memoria de la matriz de rutas.
*/

void	ft_free(t_data *data)
{
	free(data->valid_path);
	ft_free_matrix(data->matrix_cmd);
	free(data->matrix_cmd);
	ft_free_matrix(data->matrix_path);
	free(data->matrix_path);
}

/*
En la función ft_close_n_wait hacemos lo siguiente:
1.	Recibimos un puntero a una estructura de tipo t_data llamada data.
2.	Cerramos el pipe en modo lectura.
3.	Cerramos el pipe en modo escritura.
4.	Esperamos a que el primer hijo termine.
5.	Esperamos a que el segundo hijo termine.
*/

int	ft_close_n_wait(t_data *data)
{
	int	status;
	
	close(data->pipe_fd[0]);
	close(data->pipe_fd[1]);
	waitpid(data->pid_child_one, NULL, 0);
	waitpid(data->pid_child_two, &status, 0);
	return (status);
}