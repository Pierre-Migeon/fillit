/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diverse_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmigeon  <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 10:48:07 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/01/28 14:26:58 by pmigeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		makedots(char *str, int length, int boardsize)
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

int			frt(int x)
{
	int i;
	int result;

	i = 1;
	result = 1;
	if (x == 0 || x == 1)
		return (x);
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
	mask <<= (on) ? ((16 - 4) - 4 * row) : 0;
	return (mask);
}

t_mino		*t_mino_rewinder(t_mino *pieces)
{
	while (pieces->id > 'A')
		pieces--;
	return (pieces);
}
