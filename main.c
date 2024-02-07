/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:24:14 by sergio            #+#    #+#             */
/*   Updated: 2024/02/07 16:18:31 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// Tu programa deberá ejecutarse de la siguiente forma:
//   ./pipex archivo1 comando1 comando2 archivo2
// Deberá utilizar 4 argumentos:
// • archivo1 y archivo2 son nombres de arhivos.
// • comando1 y comando2 son comandos de shell con sus respectivos parámetros.

// ! $> ./pipex infile "ls -l" "wc -l" outfile
// ! deberá hacer lo mismo que “<infile ls -l | wc -l >outfile”

// ! $> ./pipex infile "grep a1" "wc -w" outfile
// ! deberá hacer lo mismo que “<infile grep a1 | wc -w >outfile”

int	main(int argc, char **argv)
{
	if (argc == 5)
	{
		char	*archivo1 = argv[1];
		char	*comando1 = argv[2];
		char	*comando2 = argv[3];
		char	*archivo2 = argv[4];

		ft_printf("archivo1: %s\n", archivo1);
		ft_printf("comando1: %s\n", comando1);
		ft_printf("comando2: %s\n", comando2);
		ft_printf("archivo2: %s\n", archivo2);
	return (0);
	}
	else
	{
		perror("Error: invalid number of arguments");
		exit(1);
	}
	return (0);
}