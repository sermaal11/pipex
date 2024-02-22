/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:24:14 by sergio            #+#    #+#             */
/*   Updated: 2024/02/22 10:59:08 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
En el main hacemos lo siguiente:
1.	Creamos una estructura de tipo t_data llamada data.
2.	Comprobamos que el número de argumentos sea 5, si no lo es, llamamos a la
	función ft_error que imprime un mensaje de error y termina el programa.
3.	Inicializamos la estructura data con ceros.
4.	Llamamos a la función ft_split_path que se encarga de buscar la variable de
	entorno PATH y guardarla en la estructura data.
5.	Llamamos a la función ft_pipe que se encarga de crear un pipe.
6.	Llamamos a la función ft_child_one que se encarga de crear el primer hijo.
7.	Llamamos a la función ft_child_two que se encarga de crear el segundo hijo.
8.	Llamamos a la función ft_close_n_wait que se encarga de cerrar los pipes y
	esperar a que los hijos terminen.
9.	Llamamos a la función ft_free que se encarga de liberar la memoria.
10.	El programa termina.
*/

int	main(int argc, char **argv, char **env)
{
	t_data	data;
	int		status;

	if (argc != 5)
		ft_error("Error: invalid number of arguments");
	ft_memset(&data, 0, sizeof(data));
	ft_split_path(&data, env);
	ft_pipe(&data);
	ft_child_one(&data, argv[1], argv[2], env);
	ft_child_two(&data, argv[4], argv[3], env);
	status = ft_close_n_wait(&data);
	ft_free(&data);
	return (WEXITSTATUS(status));
}
