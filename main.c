/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:24:14 by sergio            #+#    #+#             */
/*   Updated: 2024/02/20 15:26:44 by smarin-a         ###   ########.fr       */
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
	int i;

	i = 0;
	if (argc != 5)
	{
		perror("Error: invalid number of arguments");
		system("leaks -q pipex");
		return (0);
	}
	ft_printf("%s\n", argv[1]);
	ft_printf("%s\n", argv[2]);
	ft_printf("%s\n", argv[3]);
	ft_printf("%s\n", argv[4]);

	while (ft_strlen(ft_strnstr(env[i], "PATH", ft_strlen(env[i]))) <= 6)
	{
		i++;
	}
		ft_printf("%s\n", ft_strnstr(env[i], "PATH", ft_strlen(env[i])));
	
	// while (env[i++])
	// 	ft_printf("%s\n", ft_strnstr(env[i], "PATH", ft_strlen(env[i])));
	system("leaks -q pipex");
	return (0);
}
