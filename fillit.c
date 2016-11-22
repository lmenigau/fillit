/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:09:27 by lmenigau          #+#    #+#             */
/*   Updated: 2016/11/22 03:04:31 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	find_origin(char tetri[4][5], t_tetrimino *tetrimino)
{
	int		x;
	int		y;
	int		flag[2];

	x = 0;
	y = 0;
		while (x < 4)
		{
			y = 0;
			while (y < 4)
			{
				if (tetri[x][y] == '#' && !flag[0])
				{
					flag[0] = 1;
					tetrimino->x = x;
				}
				if (tetri[y][x] == '#' && !flag[1])
				{
					tetrimino->y = y;
					flag[1] = 1;
				}
				y++;
			}
			x++;
		}
}

void	locate_tetriminos(char *buff)
{
	t_tetrimino		tetriminos[26];
	char			(*buffer)[26][21];
	int				i;

	i = 0;
	buffer = (char (*)[26][21])buff;
	while (i < 26)
	{
		find_origin((char (*)[5])&buffer[i], &tetriminos[i]);
		i++;
	}
}

int		count_check_tetri(char	*buff, int size_buff)
{
	char	(*buffer)[26][21];
	int		i;
	int		max_count;

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
		ft_putstr("usage : fillit filename\n");
	fd = open(argv[1], O_RDONLY);

	bytes_read = read(fd, buff, MAX_FILE_SIZE);
	printf("%d, %d", MAX_FILE_SIZE, bytes_read);
	if (!count_check_tetri(buff, bytes_read))
		ft_putstr("error.\n");

}
