/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:47:49 by sergio            #+#    #+#             */
/*   Updated: 2024/02/23 16:32:53 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



int main(int argc, char **argv, char **env)
{
	t_data	data;
	
	if (argc < 5)
		ft_error("Error: arguments", 1);
	data.index_pid = 0;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_memset(&data, 0, sizeof(data));
		printf("Entro en el here_doc");
		// crear funcion ft_here_doc()
	}
	else
	{
		ft_memset(&data, 0, sizeof(data));
		data.num_cmd_middle = argc - 5;
		data.pid_childs = (int *)malloc(data.num_cmd_middle + 2 * sizeof(int));
		ft_split_path(&data, env);
		ft_pipe(&data);
		ft_child_one(&data, argv[1], argv[2], env);
		data.index_pid++;
		data.tmp_fd = data.pipe_fd[R];
		int i = 3;
		while (data.num_cmd_middle != 0)
		{
			ft_pipe(&data);
			ft_child_middle(&data, argv[i++], env);
			data.index_pid++;
			data.tmp_fd = data.pipe_fd[R];
			data.num_cmd_middle--;
		}
		ft_child_last(&data, argv[argc - 1], argv[argc - 2], env);
		data.status = ft_close_n_wait(&data);
		ft_free(&data);
		//system("leaks -q pipex_bonus");
		return (WEXITSTATUS(data.status));
	}
	return (0);
}
