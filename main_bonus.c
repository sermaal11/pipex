/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:47:49 by sergio            #+#    #+#             */
/*   Updated: 2024/02/23 15:40:33 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc < 5)
		ft_error("Error: arguments", 1);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_memset(&data, 0, sizeof(data));
		printf("Entro en el here_doc");
		// crear funcion ft_here_doc()
	}
	else
	{
		ft_memset(&data, 0, sizeof(data));
		data.num_cmd = argc - 5;
		ft_split_path(&data, env);
		ft_pipe(&data);
		ft_child_one(&data, argv[1], argv[2], env);
		data.tmp_fd = data.pipe_fd[R];
		int i = 3;
		while (data.num_cmd < argc - 1)
		{
			ft_pipe(&data);
			ft_child_middle(&data, argv[i++], env);
			data.tmp_fd = data.pipe_fd[R];
			data.num_cmd++;
		}
		ft_child_last(&data, argv[4], argv[3], env);
		data.status = ft_close_n_wait(&data);
		ft_free(&data);
		return (WEXITSTATUS(data.status));
	}
	return (0);
}
