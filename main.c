/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:24:14 by sergio            #+#    #+#             */
/*   Updated: 2024/03/06 11:45:21 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	if (argc != 5)
		ft_error("Error: invalid number of arguments", 1);
	ft_memset(&data, 0, sizeof(data));
	ft_split_path(&data, env);
	ft_child_one(&data, argv[1], argv[2], env);
	ft_child_two(&data, argv[4], argv[3], env);
	data.status = ft_close_n_wait(&data);
	ft_free(&data);
	return (WEXITSTATUS(data.status));
}
