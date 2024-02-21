/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:24:14 by sergio            #+#    #+#             */
/*   Updated: 2024/02/21 18:10:32 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 5)
		ft_error("Error: invalid number of arguments\n");
	ft_split_path(env, &data);
	ft_search_valid_path(argv[2], &data);
	ft_pipe(&data);

	data.pid_child_one = fork();
	if (data.pid_child_one == 0)
	{
		printf("PID del hijo: %d\n", getpid());
		data.infile_fd = open(argv[1], O_RDONLY);
		if (data.infile_fd == -1)
			perror("Error");
		dup2(data.infile_fd, STDIN_FILENO);
		dup2(data.pipe_fd[W], STDOUT_FILENO);
		close(data.infile_fd);
		close(data.pipe_fd[R]);
		execve(data.valid_path, data.matrix_command, env);
	}
	else if (data.pid_child_one < 0)
		ft_error("Error: fork not created\n");

	data.pid_child_two = fork();
	if (data.pid_child_two == 0)
	{
		printf("PID del hijo: %d\n", getpid());
		data.outfile_fd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (data.outfile_fd == -1)
			perror("Error");
		dup2(data.pipe_fd[R], STDIN_FILENO);
		dup2(data.outfile_fd, STDOUT_FILENO);
		close(data.outfile_fd);
		close(data.pipe_fd[W]);
		execve(data.valid_path, data.matrix_command, env);
	}
	else if (data.pid_child_two < 0)
		ft_error("Error: fork not created\n");
	
	close(data.pipe_fd[0]);
	close(data.pipe_fd[1]);
	waitpid(data.pid_child_one, NULL, 0);
	waitpid(data.pid_child_two, NULL, 0);
	ft_free(&data);
	return (0);
}
