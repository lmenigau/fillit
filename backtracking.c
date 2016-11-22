/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmenigau <lmenigau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:53:02 by lmenigau          #+#    #+#             */
/*   Updated: 2016/11/22 15:36:38 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_placeable(char **grid, t_tetrimino *tetri, char **buff,  int size)
{

}

int		backtracking(char **grid, t_tetrimino *tetri, char **buff,  int size)
{
	int		x;
	int		y;

	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			if (is_placeable())
		}
	}
	return (0);
}

void	compute_grid_size(int	max_count)
{
	int		size;
	char	grid[16][16];

	ft_bzero(&grid, 16 * 16);
	size = 1;
	while (size * size < max_count * 4)
		size++;
}
