/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isok.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: recharif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 17:53:05 by recharif          #+#    #+#             */
/*   Updated: 2016/11/22 02:43:57 by lmenigau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isltr(char *str, int i)
{
	return ((str[i] == '.' || str[i] == '#') ? 1 : 0);
}

static int	ft_is4line(char *str)
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
	if (str[j] != '\n')
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

static int	ft_istetrimino(char *str)
{
	int	i;

	i = 5;
	while (i < 15)
	{
		if (str[i] == '#')
		{
			if (!(str[i - 1] == '#' || str[i + 1] == '#' || str[i + 5] == '#'
				|| str[i - 5] == '#'))
				return (0);
		}
		i++;
	}
	return (1);
}

int			ft_isok(char *str)
{
	if (ft_is4line(str) && ft_istetrimino(str) && ft_is4blocks(str))
		return (1);
	return (0);
}
