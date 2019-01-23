/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:48:07 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/01/22 17:11:47 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	makedots(char *str, int length, int boardsize)
{
	int i;

	i = 0;
	while (i < length)
	{
		str[i] = '.';
		if (((i + 1) % (boardsize + 1) == 0))
			str[i] = '\n';
		++i;
	}
}

int	frt(int x)
{
	if (x == 0 || x == 1)
		return x;
	int i = 1;
	int result = 1;
	while (result <= x)
	{
		i++;
		result = i * i;
	}
	return (i - 1);
}

uint16_t	genmask(int row, int on, int boardsize)
{
	uint16_t mask;

	mask = 65535;
	mask >>= (on) ? (16 - 4) : boardsize;
	mask <<= (on) ? ((16 - 4) - 4*row) : 0;
	return (mask);
}

t_mino	*t_mino_rewinder(t_mino *pieces)
{
	while (pieces->id > 'A')
		pieces--;
	return (pieces);
}
