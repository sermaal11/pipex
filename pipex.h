/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:23:27 by sergio            #+#    #+#             */
/*   Updated: 2024/02/21 20:54:50 by smarin-a         ###   ########.fr       */
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

void	ft_child_one(t_data *data, char *file, char *command, char **env);
void	ft_child_two(t_data *data, char *file, char *command, char **env);
void	ft_search_valid_path(char *command, t_data *data);
void	ft_split_path(t_data *data, char **env);
void	ft_free_matrix(char **matrix);
void	ft_close_n_wait(t_data *data);
void	ft_pipe(t_data *data);
void	ft_free(t_data *data);
void	ft_error(char *msg);

#endif