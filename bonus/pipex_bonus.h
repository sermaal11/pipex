/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:35:29 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/22 19:00:24 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

	int		pid_child_one;
	int		pid_child_last;

	int		infile_fd;
	int		pipe_fd[2];
	int		outfile_fd;

	char	*temp_path;
	int		num_cmd;
}				t_data;

void	ft_split_path(t_data *data, char **env);
void	ft_child_one(t_data *data, char *file, char *command, char **env);
void	ft_child_last(t_data *data, char *file, char *command, char **env);
void	ft_search_valid_path(char *command, t_data *data);
void	ft_pipe(t_data *data);

#endif