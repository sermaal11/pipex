/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:23:27 by sergio            #+#    #+#             */
/*   Updated: 2024/02/21 14:40:46 by smarin-a         ###   ########.fr       */
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

typedef struct	s_data
{
	char	**matrix_path;
	char	*matrix_joined_path;
	char	**matrix_command;
	char	*valid_path;
}				t_data;

void	ft_split_path(char **env, t_data *data);
void	ft_free_matrix(char **sys_path);
void	ft_search_valid_path(char *command, t_data *data);

#endif