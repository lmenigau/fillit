/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 01:09:27 by lmenigau          #+#    #+#             */
/*   Updated: 2016/11/18 05:29:19 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		main(int argc, char **argv)
{
	int		fd;
	int		bytes_read;
	char	buff[MAX_FILE_SIZE];
	int		i;

	t_tetrimino		tetriminos[26];

		if (argc != 2)
			ft_putstr("usage : fillit filename\n");
	fd = open(argv[1], O_RDONLY);

	bytes_read = read(fd, buff, MAX_FILE_SIZE);
	printf("%d, %d", MAX_FILE_SIZE, bytes_read);

	i = 0;
	while (i < 26)
	{
		tetriminos[i].x = 9;

	}
}
