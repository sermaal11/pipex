/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarin-a <smarin-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 15:31:18 by smarin-a          #+#    #+#             */
/*   Updated: 2024/02/22 15:41:26 by smarin-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// ! • Gestionar múltiples pipes.
// !		$> ./pipex archivo1 comando1 comando2 comando3 ... comandon archivo2
// !		Deberá comportarse así:
// !		$> < archivo1 comando1 | comando2 | comando3 ... | comandon > archivo2

// ! • Aceptar << y >> cuando el primer parámetro es “here_doc”:
// !		$> ./pipex here\_doc LIMITADOR comando comando1 archivo
// !		Deberá comportarse así:
// !		comando << LIMITADOR | comando1 >> archivo

int main(int argc, char **argv, char **env)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	
}