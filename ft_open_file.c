/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 17:33:09 by sergio            #+#    #+#             */
/*   Updated: 2024/02/07 17:46:35 by sergio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ! Añadir a la librería libft la función ft_open_file.c
// ! Añadir # include <fcntl.h> a libft/libft.h y borrar de pipex.h

#include "pipex.h"

int	ft_open_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		perror("Error.\nError en la apertura de el archivo.\n");
	return (fd);
}