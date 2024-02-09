/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:24:14 by sergio            #+#    #+#             */
/*   Updated: 2024/02/09 22:30:36 by sergio           ###   ########.fr       */
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

// ! Revisar mi GNL con repo original subido a 42.

int	main(int argc, char **argv)
{
	
	//  Si el número de argumentos es diferente a 5 entonces imprime el mensaje
	//  de error y termina el programa.
	if (argc != 5)
	{
		perror("Error: invalid number of arguments");
		system("leaks -q pipex");
		return (0);
	}
	system("leaks -q pipex");
	return (0);
}
