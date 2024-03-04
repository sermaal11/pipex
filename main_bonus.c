/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:47:49 by sergio            #+#    #+#             */
/*   Updated: 2024/03/04 21:20:33 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	data->num_cmd_middle = argc - 5;
	if (data->num_cmd_middle < 0)
		data->num_cmd_middle = 0;
	data->pid_childs = (int *)malloc(data->num_cmd_middle + 2 * sizeof(int));
	ft_split_path(data, env);
	ft_foock(data, argc + 1, argv, env);
	data->status = ft_close_n_wait(data);
	ft_free(data);
}
void static	ft_here_doc(t_data *data, int argc, char **argv, char **env)
{
	char	*line;
	int		tmp_fd;
	
	if (argc < 6)
		ft_error("Error: arguments", 1);
	tmp_fd = open(".here_doc", O_WRONLY | O_CREAT ,0644);
	while(1)
	{
		line = ft_gnl(0);
		if ((ft_strlen(line) - 1) == ft_strlen(argv[2])
			&& ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(line);
			break;
		}
		if (write(tmp_fd, line, ft_strlen(line)) == -1)
			ft_error("Write error", 1);
		if(line)
			free(line);
	}
	data->here_doc = 1;
	ft_multipe_pipes(data, argc - 1, argv, env);
}

void leaks(void)
{
	system("leaks -q pipex_bonus");
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	if (argc < 5)
		ft_error("Error: arguments", 1);
	ft_memset(&data, 0, sizeof(data));
	data.index_pid = 0;
	data.index_cmd_middle = 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_here_doc(&data, argc, argv, env);
		unlink(".here_doc");
	}
	else
		ft_multipe_pipes(&data, argc - 1, argv, env);
	atexit(leaks);
	return (WEXITSTATUS(data.status));
}
