/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:09:27 by lmenigau          #+#    #+#             */
/*   Updated: 2016/11/29 21:38:38 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_origin(char (*tetri)[5], t_tetrimino *tetrimino, char letter)
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
				tetri[x][y] = letter;
			if (tetri[x][y] != '.' && tetrimino->y == -1)
				tetrimino->y = y;
			if (tetri[x][y] != '.')
				tetrimino->height = y;
			if (tetri[y][x] != '.' && tetrimino->x == -1)
				tetrimino->x = y;
			if (tetri[y][x] != '.')
				tetrimino->width = y;
			y++;
		}
		x++;
	}
}

int		count_check_tetri(char	*buff, int size_buff)
{
	char			(*buffer)[21];
	t_tetrimino		tetriminos[26];
	int				i;
	int				max_count;

	max_count = size_buff / 21;
	if (size_buff % 21 != 0 && max_count != 0)
		return (0);
	buffer	= (char (*)[21])buff;
	i = 0;
	while (i < max_count)
	{
		if (!ft_isok((char *)buffer[i]))
			return (0);
		tetriminos[i].x = -1;
		tetriminos[i].y = -1;
		find_origin((char (*)[5])buffer[i], &tetriminos[i], i + 'A');
		i++;
	}
	compute_grid_size(buffer, tetriminos, max_count);
	return (max_count);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		bytes_read;
	char	buff[MAX_FILE_SIZE];


	if (argc != 2)
	{
		ft_putstr("usage : fillit filename\n");
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_putstr("error.\n");

	bytes_read = read(fd, buff, MAX_FILE_SIZE);
	if (!count_check_tetri(buff, bytes_read))
		ft_putstr("error.\n");

}
