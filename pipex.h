/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sergio <sergio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 21:23:27 by sergio            #+#    #+#             */
/*   Updated: 2024/02/09 14:23:14 by sergio           ###   ########.fr       */
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
# include "./libft/libft.h"

# define OUTFILE "outfile"
# define INFILE "infile"
# define PIPE_READ 0
# define PIPE_WRITE 1

#endif