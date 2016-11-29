/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:36:05 by lmenigau          #+#    #+#             */
/*   Updated: 2016/11/29 18:17:50 by lmenigau         ###   ########.fr       */
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
	char		(*buff)[21];
	t_tetrimino	*tetri;
	char		(*grid)[16];
	int			max_count;
	int			size;
}				t_data;

int			ft_isok(char *str);
void		compute_grid_size(char (*buff)[21], t_tetrimino *tetri,int	max_count);
#endif
