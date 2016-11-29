/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:53:02 by lmenigau          #+#    #+#             */
/*   Updated: 2016/11/29 21:53:58 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_fit(t_data data, int index, int x, int y)
{
	int		i;
	int		j;
	int		ysave;

	i = data.tetri[index].x;
	ysave = y;
	while (i <= data.tetri[index].width && x < data.size)
	{
		j = data.tetri[index].y;
		y = ysave;
		while (j <= data.tetri[index].height && y < data.size)
		{
			if (data.grid[x][y] != '.' && data.tetri[index].add[i][j] != '.')
				return (0);
			j++;
			y++;
		}
		x++;
		i++;
	}
	if (x == data.size || y == data.size)
		return (0);
	return (1);
}

int		blit(t_data data, int index, int x, int y)
{
	int		i;
	int		j;
	int		ysave;

	i = data.tetri[index].x;
	ysave = y;
	while (i <= data.tetri[index].width)
	{
		j = data.tetri[index].y;
		y = ysave;
		while (j <= data.tetri[index].height)
		{
			if (data.tetri[index].add[i][j] != '.')
				data.grid[x][y] = 'A' + index;
			j++;
			y++;
		}
		i++;
		x++;
	}
	return (1);
}

int		t_remove(t_data data, int index, int x, int y)
{
	int		i;
	int		j;
	int		ysave;

	i = data.tetri[index].x;
	ysave = y;
	while (i <= data.tetri[index].width)
	{
		j = data.tetri[index].y;
		y = ysave;
		while (j <= data.tetri[index].height)
		{
			if (data.tetri[index].add[i][j] != '.')
				data.grid[x][y] = '.';
			j++;
			y++;
		}
		i++;
		x++;
	}
	return (1);
}

int		print_grid(char (*grid)[16], int size)
{
	int		x;
	int		y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			ft_putchar(grid[x][y]);
			y++;
		}
		ft_putchar('\n');
		x++;
	}
	return (1);
}

int		backtracking(t_data data, int index)
{
	int		x;
	int		y;

	x = 0;
	while (x < data.size)
	{
		y = 0;
		while (y < data.size)
		{
			if (is_fit(data, index, x, y))
			{
				blit(data, index, x, y);
				print_grid(data.grid, data.size);
				if (index == data.max_count)
					return (1);
				if (backtracking(data, index + 1))
					return (1);
				else
					t_remove(data, index, x, y);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	compute_grid_size(char (*buff)[21], t_tetrimino *tetri, int	max_count)
{
	int		size;
	char	grid[16][16];
	t_data	data;

	ft_memset(&grid, '.', 16 * 16);
	size = 2;
	while (size * size < max_count * 4)
		size++;
	data.buff = buff;
	data.tetri = tetri;
	data.grid = grid;
	data.max_count = max_count - 1;
	data.size = size + 1;
	while (backtracking(data, 0) == 0)
	{
		data.size++;
	}
	print_grid(grid, 16);
}
