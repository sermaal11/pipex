/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:24:14 by sergio            #+#    #+#             */
/*   Updated: 2024/02/21 14:58:05 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// ! $> ./pipex infile "ls -l" "wc -l" outfile
// ! deberá hacer lo mismo que “<infile ls -l | wc -l >outfile”

// ! $> ./pipex infile "grep a1" "wc -w" outfile
// ! deberá hacer lo mismo que “<infile grep a1 | wc -w >outfile”

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	//Control de solo 5 argumentos pasados por input
	if (argc != 5)
	{
		perror("Error: invalid number of arguments");
		return (0);
	}
	// ! Para que no chille al no usar argv
	printf("\nargv[1] = %s\n", argv[1]);
	printf("argv[2] = %s\n", argv[2]);
	printf("argv[3] = %s\n", argv[3]);
	printf("argv[4] = %s\n\n", argv[4]);
	
	ft_split_path(env, &data);
	ft_search_valid_path(argv[2], &data);
	
	//Libero la matrizes del split
	//free(data.valid_path);
	ft_free_matrix(data.matrix_command);
	free(data.matrix_command);
	ft_free_matrix(data.matrix_path);
	free(data.matrix_path);
	return (0);
}
