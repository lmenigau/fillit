/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:09:27 by lmenigau          #+#    #+#             */
/*   Updated: 2016/12/14 19:16:43 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_origin(char (*tetri)[5], t_tetrimino *tetrimino, int index)
{
	int		x;
	int		y;

	x = 0;
	tetrimino->add = tetri;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if (tetri[x][y] == '#')
				tetri[x][y] = 'A' + index;
			if (tetri[x][y] != '.' && tetrimino->x == -1)
				tetrimino->x = x;
			if (tetri[x][y] != '.')
				tetrimino->height = x;
			if (tetri[y][x] != '.' && tetrimino->y == -1)
				tetrimino->y = x;
			if (tetri[y][x] != '.')
				tetrimino->width = x;
			y++;
		}
		x++;
	}
}

int		count_check_tetri(char (*buffer)[21], int size_buff)
{
	t_tetrimino		tetriminos[26];
	int				i;
	int				max_count;

	max_count = (size_buff + 1) / 21;
	if ((size_buff + 1) % 21 != 0 || max_count == 0)
		return (0);
	i = 0;
	while (i < max_count)
	{
		if (!ft_isok(buffer[i], i, max_count - 1))
			return (0);
		tetriminos[i].x = -1;
		tetriminos[i].y = -1;
		find_origin((char (*)[5])&buffer[i], &tetriminos[i], i);
		i++;
	}
	compute_grid_size(tetriminos, max_count);
	return (max_count);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		bytes_read;
	char	buff[26][21];

	if (argc != 2)
	{
		ft_putstr("usage : fillit filename\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		ft_putstr("error\n");
		return (0);
	}
	bytes_read = read(fd, buff, MAX_FILE_SIZE);
	if (!count_check_tetri(buff, bytes_read))
		ft_putstr("error\n");
}
