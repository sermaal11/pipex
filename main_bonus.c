/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:47:49 by sergio            #+#    #+#             */
/*   Updated: 2024/03/06 11:45:16 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void static	ft_multipe_pipes(t_data *data, int argc, char **argv, char **env )
{
	data->num_cmd_middle = argc - 5;
	if (data->num_cmd_middle < 0)
		data->num_cmd_middle = 0;
	data->pid_childs = (int *)malloc((data->num_cmd_middle + 2) * sizeof(int));
	ft_split_path(data, env);
	ft_foock(data, argc + 1, argv, env);
	data->status = ft_close_n_wait(data);
	ft_free(data);
}

void static	ft_here_doc(t_data *data, int argc, char **argv, char **env)
{
	char	*line;
	int		tmp_fd;

	if (argc < 6)
		ft_error("Error: arguments", 1);
	tmp_fd = open(".here_doc", O_WRONLY | O_CREAT, 0644);
	while (1)
	{
		line = ft_gnl(0);
		if ((ft_strlen(line) - 1) == ft_strlen(argv[2])
			&& ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0)
		{
			free(line);
			break ;
		}
		if (write(tmp_fd, line, ft_strlen(line)) == -1)
			ft_error("Write error", 1);
		if (line)
			free(line);
	}
	data->here_doc = 1;
	ft_multipe_pipes(data, argc - 1, argv, env);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc < 5)
		ft_error("Error: arguments", 1);
	ft_memset(&data, 0, sizeof(data));
	data.index_pid = 0;
	data.index_cmd_middle = 3;
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		ft_here_doc(&data, argc, argv, env);
		unlink(".here_doc");
	}
	else
		ft_multipe_pipes(&data, argc - 1, argv, env);
	return (WEXITSTATUS(data.status));
}
