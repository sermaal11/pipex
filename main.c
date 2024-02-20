/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:24:14 by sergio            #+#    #+#             */
/*   Updated: 2024/02/20 18:54:21 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Tu programa deberá ejecutarse de la siguiente forma:
// ./pipex archivo1 comando1 comando2 archivo2
// Deberá utilizar 4 argumentos:
// • archivo1 y archivo2 son nombres de arhivos.
// • comando1 y comando2 son comandos de shell con sus respectivos parámetros.

// ! $> ./pipex infile "ls -l" "wc -l" outfile
// ! deberá hacer lo mismo que “<infile ls -l | wc -l >outfile”

// ! $> ./pipex infile "grep a1" "wc -w" outfile
// ! deberá hacer lo mismo que “<infile grep a1 | wc -w >outfile”

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 5)
	{
		perror("Error: invalid number of arguments");
		return (0);
	}
	// Para que no chille al no usar argv
	printf("%s\n", argv[1]);
	printf("%s\n", argv[2]);
	printf("%s\n", argv[3]);
	printf("%s\n", argv[4]);
	ft_split_path(env, &data);

	// Comprobacion del split del PATH
	int row;
	row = 0;
	while(data.matrix_path[row])
	{
		printf("%s\n", data.matrix_path[row]);
		row++;
	}

	//Libero la matriz de sys_path
	ft_free_path(data.matrix_path);
	free(data.matrix_path);
	return (0);
}
