/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recharif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:53:05 by recharif          #+#    #+#             */
/*   Updated: 2016/12/03 13:10:46 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isltr(char *str, int i)
{
	return ((str[i] == '.' || str[i] == '#') ? 1 : 0);
}

static int	ft_is4line(char *str, int index, int max_count)
{
	size_t	i;
	size_t	j;

	i = 4;
	j = 0;
	while (j < 20)
	{
		while (j < i && ft_isltr(str, j))
			++j;
		if (j != i || str[j] != '\n')
			return (0);
		i += 5;
		j++;
	}
	if (str[j] != '\n' && index < max_count)
		return (0);
	return (1);
}

static int	ft_is4blocks(char *str)
{
	size_t	i;
	int		n;

	i = 0;
	n = 0;
	while (i < 20)
	{
		if (str[i] == '#')
			++n;
		++i;
	}
	if (n != 4)
		return (0);
	return (1);
}

static int	ft_istetrimino(char (*str)[5])
{
	int	i;
	int	j;
	int	 connect;

	connect = 1;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if ((str[i][j] == '#') && ((j < 3 && str[i][j + 1] == '#')))
					connect++;
			if ((str[i][j] == '#') && ((i < 3 && str[i + 1][j] == '#')))
				connect++;
			if (connect >= 4)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int			ft_isok(char *str, int index, int max_count)
{
	if (ft_is4line(str, index, max_count) && ft_is4blocks(str) &&
			ft_istetrimino((char (*)[5])str))
		return (1);
	return (0);
}
