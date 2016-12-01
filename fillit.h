/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:36:05 by lmenigau          #+#    #+#             */
/*   Updated: 2016/12/01 17:31:18 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"


# define	MAX_FILE_SIZE	(26 * (4*5 + 1))

typedef struct	s_tetrimino
{
	char		(*add)[5];
	int			x;
	int			y;
	int			width;
	int			height;
}				t_tetrimino;

typedef struct	s_data
{
	t_tetrimino	*tetri;
	char		(*grid)[16];
	int			size;
}				t_data;

int			ft_isok(char *str, int index, int max_count);
void		compute_grid_size(t_tetrimino *tetri, int max_count);
#endif
