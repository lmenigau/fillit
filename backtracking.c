/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:53:02 by lmenigau          #+#    #+#             */
/*   Updated: 2016/11/28 18:24:50 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_fit(t_data data, int index, int x, int y)
{
	int		i;
	int		j;

	i = data.tetri[index].x;

	while (i <= data.tetri[index].width)
	{
		j = data.tetri[index].y;
		while (j <= data.tetri[index].height)
		{
			if (data.grid[x][y] != '#' && data.tetri[index].add[i][j] != '#')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		blit(t_data data, int index, int x, int y)
{
	int		i;
	int		j;

	i = data.tetri[index]->x;

	while (i <= data.tetri[index].width)
	{
		j = data.tetri[index].y;
		while (j <= data.tetri[index].height)
		{
			if (data.tetri[index].add[i][j] == '#')
				grid[x][y] = '#';
			j++;
		}
		i++;
	}
	return (1);
}

int		remove(t_data data, int index, int x, int y)
{
	int		i;
	int		j;

	i = data.tetri[index]->x;

	while (i <= data.*tetri[index].width)
	{
		j = data.tetri[index]->y;
		while (j <= data.tetri[index].height)
		{
			if (data.tetri[index].add[i][j] == '#')
				grid[x][y] = '.';
			j++;
		}
		i++;
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
				if (backtracking(data, index + 1) == 0)
					remove(data, index, x, y);
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	compute_grid_size(char **buff, t_tetrimino (*)tetri[], int	max_count)
{
	int		size;
	char	grid[16][16];
	t_data	data;

	ft_bzero(&grid, 16 * 16);
	size = 1;
	while (size * size < max_count * 4)
		size++;
	data.buff = buff;
	data.tetri = tetri;
	data.grid = &grid;
	data.max_count = max_count;
	data.size = size;
	backtracking(data);
}
