/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:23:27 by sergio            #+#    #+#             */
/*   Updated: 2024/02/21 23:16:05 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "./libft/libft.h"

# define R 0
# define W 1

typedef struct s_data
{
	char	**matrix_path;
	char	*matrix_joined_path;
	char	**matrix_command;
	char	*valid_path;

	int		pipe_fd[2];
	int		infile_fd;
	int		outfile_fd;

	int		pid_child_one;
	int		pid_child_two;
}				t_data;

// ft_childs.c
// ft_child_one.c realiza la ejecución del primer hijo.
void	ft_child_one(t_data *data, char *file, char *command, char **env);
// ft_child_two.c realiza la ejecución del segundo hijo.
void	ft_child_two(t_data *data, char *file, char *command, char **env);

// ft_path.c
// ft_search_valid_path.c busca la ruta válida del comando.
void	ft_search_valid_path(char *command, t_data *data);
// ft_split_path.c separa la variable de entorno PATH.
void	ft_split_path(t_data *data, char **env);

// ft_utils.c
// ft_free_matrix.c libera la memoria de la matriz.
void	ft_free_matrix(char **matrix);
// ft_close_n_wait.c cierra los pipes y espera a que los hijos terminen.
void	ft_close_n_wait(t_data *data);
// ft_pipe.c crea un pipe.
void	ft_pipe(t_data *data);
// ft_free.c libera la memoria.
void	ft_free(t_data *data);
// ft_error.c imprime un mensaje de error y termina el programa.
void	ft_error(char *msg);

#endif