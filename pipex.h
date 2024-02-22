/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:23:27 by sergio            #+#    #+#             */
/*   Updated: 2024/02/22 17:11:52 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <fcntl.h>

# define R 0
# define W 1

typedef struct s_data
{
	char	*matrix_joined_path;
	char	**matrix_path;
	char	**matrix_cmd;
	char	*valid_path;

	int		outfile_fd;
	int		pipe_fd[2];
	int		infile_fd;

	int		pid_child_one;
	int		pid_child_two;

	int		status;
	char	*temp_path;
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
int		ft_close_n_wait(t_data *data);
// ft_pipe.c crea un pipe.
void	ft_pipe(t_data *data);
// ft_free.c libera la memoria.
void	ft_free(t_data *data);
// ft_error.c imprime un mensaje de error y termina el programa.
void	ft_error(char *msg, int n_error);

#endif