/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:53:02 by lmenigau          #+#    #+#             */
/*   Updated: 2016/12/03 14:04:34 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_fit(t_tetrimino *tetri, char (*grid)[16])
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = tetri->x;
	x = 0;
	while (i <= tetri->height)
	{
		j = tetri->y;
		y = 0;
		while (j <= tetri->width)
		{
			if (grid[x][y] != '.' && tetri->add[i][j] != '.')
				return (0);
			j++;
			y++;
		}
		x++;
		i++;
	}
	return (1);
}

int		blit(t_tetrimino *tetri, char (*grid)[16], char letter)
{
	int		i;
	int		j;
	int		x;
	int		y;

	i = tetri->x;
	x = 0;
	while (i <= tetri->height)
	{
		j = tetri->y;
		y = 0;
		while (j <= tetri->width)
		{
			if (tetri->add[i][j] != '.')
				grid[x][y] = letter;
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

int		backtracking(t_data *data, int index, int max_count, int size)
{
	int			x;
	int			y;
	t_tetrimino *tetri;

	x = 0;
	if (index == max_count)
		return (1);
	tetri = &data->tetri[index];
	while (x < size - (tetri->height - tetri->x))
	{
		y = 0;
		while (y < size - (tetri->width - tetri->y))
		{
			if (is_fit(tetri, (char (*)[16])&data->grid[x][y]))
			{
				blit(tetri, (char (*)[16])&data->grid[x][y], index + 'A');
				if (backtracking(data, index + 1, max_count, size))
					return (1);
				blit(tetri, (char (*)[16])&data->grid[x][y], '.');
			}
			y++;
		}
		x++;
	}
	return (0);
}

void	compute_grid_size(t_tetrimino *tetri, int max_count)
{
	int		size;
	char	grid[16][16];
	t_data	data;

	ft_memset(grid, '.', 16 * 16);
	size = 2;
	while (size * size < max_count * 4)
		size++;
	data.tetri = tetri;
	data.grid = grid;
	while (backtracking(&data, 0, max_count, size) == 0)
	{
		size++;
	}
	print_grid(grid, size);
}
