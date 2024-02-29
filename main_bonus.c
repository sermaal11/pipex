/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:47:49 by sergio            #+#    #+#             */
/*   Updated: 2024/02/29 15:39:04 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void static	ft_here_doc(t_data *data, int argc, char **argv)
{
	if (argc < 6)
		ft_error("Error: arguments", 1);
	if (pipe(data->pipe_fd) == -1)
		ft_error("Error: pipe not created", 1);
	data->infile_fd = open(argv[1], O_RDWR | O_CREAT ,0644);
	data->pid_reader = fork();
	if (data->pid_reader == 0)
	{
		close(data->pipe_fd[R]);
		while(ft_gnl(0))
		{
			
		}
	}
	else if (data->pid_reader < 0)
		ft_error("Error: fork not created", 1);
}

/*
En la función ft_multipe_pipes hacemos lo siguiente:
1.	Recibimos un puntero a una estructura de tipo t_data llamada data, un entero
	llamado argc, un puntero a un puntero de tipo char llamado argv y un puntero
	a un puntero de tipo char llamado env.
2.	Reservamos memoria para la estructura data.
3.	Inicializamos la estructura data con 0.
4.	Asignamos a la estructura data el número de comandos intermedios.
5.	Reservamos memoria para la variable pid_childs.
6.	Llamamos a la función ft_split_path con los parámetros data y env.
7.	Llamamos a la función ft_foock con los parámetros data, argc, argv y env.
8.	Asignamos a la estructura data el valor de la función ft_close_n_wait.
9.	Liberamos la memoria de la estructura data.
*/

void static	ft_multipe_pipes(t_data *data, int argc, char **argv, char **env )
{
	ft_memset(data, 0, sizeof(data));
	data->num_cmd_middle = argc - 5;
	data->pid_childs = (int *)malloc(data->num_cmd_middle + 2 * sizeof(int));
	ft_split_path(data, env);
	ft_foock(data, argc, argv, env);
	data->status = ft_close_n_wait(data);
	ft_free(data);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc < 5)
		ft_error("Error: arguments", 1);
	data.index_pid = 0;
	data.index_cmd_middle = 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_memset(&data, 0, sizeof(data));
		printf("Entro en el here_doc");
		// crear funcion ft_here_doc()
	}
	else
		ft_multipe_pipes(&data, argc, argv, env);
	return (WEXITSTATUS(data.status));
}
