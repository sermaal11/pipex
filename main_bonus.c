/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:47:49 by sergio            #+#    #+#             */
/*   Updated: 2024/02/23 17:42:45 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void static ft_multipe_pipes(t_data *data, int argc, char **argv, char **env )
{
	ft_memset(data, 0, sizeof(data));
	data->num_cmd_middle = argc - 5;
	data->pid_childs = (int *)malloc(data->num_cmd_middle + 2 * sizeof(int));
	ft_split_path(data, env);
	ft_pipe(data);
	ft_foock(data, argc, argv, env);
	data->status = ft_close_n_wait(data);
	ft_free(data);
}

int main(int argc, char **argv, char **env)
{
	t_data	data;
	
	if (argc < 5)
		ft_error("Error: arguments", 1);
	data.index_pid = 0;
	data.index_cmd_middle = 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_memset(&data, 0, sizeof(data));
		printf("Entro en el here_doc");
		// crear funcion ft_here_doc()
	}
	else
		ft_multipe_pipes(&data, argc, argv, env);
	return (WEXITSTATUS(data.status));
}
