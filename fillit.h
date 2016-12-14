/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:36:05 by lmenigau          #+#    #+#             */
/*   Updated: 2016/12/14 19:11:51 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define MAX_FILE_SIZE (26 * (4*5 + 1))

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./libft/libft.h"

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
}				t_data;

int				ft_isok(char *str, int index, int max_count);
void			compute_grid_size(t_tetrimino *tetri, int max_count);

#endif
