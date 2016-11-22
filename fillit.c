/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:09:27 by lmenigau          #+#    #+#             */
/*   Updated: 2016/11/22 08:42:17 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_origin(char (*tetri)[4][5], t_tetrimino *tetrimino)
{
	int		x;
	int		y;

	x = 0;
	tetrimino->x = -1;
	tetrimino->y = -1;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			if ((*tetri)[x][y] == '#' && tetrimino->y == -1)
				tetrimino->y = y;
			if ((*tetri)[x][y] == '#')
				tetrimino->width = y;
			if ((*tetri)[y][x] == '#' && tetrimino->x == -1)
				tetrimino->x = y;
			if ((*tetri)[y][x] == '#')
				tetrimino->height = y;
			y++;
		}
		x++;
	}
}

int		count_check_tetri(char	*buff, int size_buff)
{
	char			(*buffer)[26][21];
	t_tetrimino		tetriminos[26];
	int				i;
	int				max_count;
	char			grid[16][16];

	max_count = size_buff / 21;
	if (size_buff % 21 != 0 && max_count != 0)
		return (0);
	buffer	= (char (*)[26][21])buff;
	i = 0;
	while (i < max_count)
	{
		printf("%s\n",(char *)(*buffer)[i]);
		if (!ft_isok((char *)(*buffer)[i]))
			return (0);
		find_origin((char (*)[4][5])(*buffer)[i], &tetriminos[i]);
		i++;
	}
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
	printf("%d, %d", MAX_FILE_SIZE, bytes_read);
	if (!count_check_tetri(buff, bytes_read))
		ft_putstr("error.\n");

}
